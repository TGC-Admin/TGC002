#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPD(i,n) for(auto i=(n); --i>=0;)

using ll = long long;

namespace Lib {

namespace Internal {

using Size = int32_t;

} // namespace Internal

template<class Cost = ll> struct Edge {
    using cost_type = Cost;
    const Internal::Size to; const Cost cost;

    Edge(const Internal::Size t, const Cost w) : to(t), cost(w) {}

    pair<Internal::Size, Cost> _debug() const { return { to, cost }; };
};

template<class E = Edge<ll>> struct Graph : vector<vector<E>> {
    using Vertex = Internal::Size;

    enum class EdgeType { Undirected, Directed };

    Graph(const Vertex n = 0) : vector<vector<E>>(n) {}

    template<const EdgeType EDGE_TYPE = EdgeType::Directed>
    void add_edge(const Vertex u, const Vertex v, const typename E::cost_type w = 0) {
        assert(0 <= u and u < (Vertex)this->size()), assert(0 <= v and v < (Vertex)this->size());
        (*this)[u].emplace_back(v, w);
        if constexpr(EDGE_TYPE == EdgeType::Undirected) {
            (*this)[v].emplace_back(u, w);
        }
    }

    inline void add_edge_bidirectionally(const Vertex u, const Vertex v, const typename E::cost_type w = 0) {
        this->add_edge<EdgeType::Undirected>(u, v, w);
    }
};

template<class Graph = Graph<>>
struct LowestCommonAncestor {
    using Vertex = typename Graph::Vertex;
    vector<vector<Vertex>> parent;
    vector<Vertex> dists;

  private:
    void dfs(const Graph &G, const Vertex v, const Vertex p, const Vertex d) {
        parent[0][v] = p;
        dists[v] = d;
        for(const auto& e : G[v]) {
            if(e.to != p) dfs(G, e.to, v, d+1);
        }
    }

  public:
    LowestCommonAncestor(const Graph &G, const Vertex root = 0) { this->init(G, root); }

    void init(const Graph &G, const Vertex root = 0) {
        const Vertex V = G.size();
        Vertex K = 1; while((1 << ++K) < V);

        parent.assign(K, vector<Vertex>(V, -1));
        dists.assign(V, -1);

        this->dfs(G, root, -1, 0);

        REP(k, K-1) REP(v, V) {
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }

    Vertex operator()(const Vertex u, const Vertex v) const {
        return this->find(u, v);
    }

    Vertex find(Vertex u, Vertex v) const {
        if(dists[u] < dists[v]) swap(u, v);
        Vertex K = parent.size();

        REP(k, K) {
            if((dists[u] - dists[v]) >> k & 1) u = parent[k][u];
        }

        if(u == v) return u;

        REPD(k, K) {
            if(parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        return parent[0][u];
    }

    Vertex edges(const Vertex u, const Vertex v) const {
        return dists[u] + dists[v] - 2 * dists[query(u, v)];
    }
};

} // namespace Lib

signed main() {
    int n; cin >> n;
    Lib::Graph G(n);

    REP(i, n-1) {
        int p, w; cin >> p >> w;
        G.add_edge(--p, i+1, w);
    }

    vector<int> diff(n);
    {
        Lib::LowestCommonAncestor lca(G);

        int q; cin >> q;
        REP(i, q) {
            int a, b; cin >> a >> b; --a, --b;
            ++diff[a], ++diff[b];
            diff[lca(a,b)] -= 2;
        }
    }

    vector<int> cnt(n);
    {
        auto accum = [&](auto& accum, int v) -> int {
            int acc = 0;
            REP(i, G[v].size()) {
                int nv = G[v][i].to;
                acc += accum(accum, nv);
            }
            return cnt[v] = acc + diff[v];
        };
        accum(accum, 0);
    }

    ll sum_cost = 0, max_contrib = INT64_MIN;
    REP(v, n) {
        REP(i, G[v].size()) {
            const auto &e = G[v][i];
            const ll contrib = cnt[e.to] * e.cost;

            sum_cost += contrib;
            max_contrib = max(max_contrib, contrib);
        }
    }

    cout << min(sum_cost, sum_cost - max_contrib) << "\n";
}
