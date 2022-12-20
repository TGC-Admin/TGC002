#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#include <atcoder/maxflow>

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define ITR(x,v) for(const auto &x : (v))

namespace Lib {

namespace Internal {
    using Size = int;
}  // namespace Internal

struct MaximumBipartiteMatching {
    using Vertex = Internal::Size;

  protected:
    using MF = atcoder::mf_graph<Vertex>;

    int _n;
    MF mf;

  public:
    MaximumBipartiteMatching(Vertex n = 0) : _n(n), mf(2*n+2) {
        REP(i, n) {
            this->mf.add_edge(2*n, i, 1);
            this->mf.add_edge(n+i, 2*n+1, 1);
        }
    }

    void add(Vertex i, Vertex j) {
        this->mf.add_edge(i, this->_n+j, 1);
    }

    Vertex solve() {
        return this->mf.flow(2*this->_n, 2*this->_n+1);
    }
};

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

    Vertex minimum_paph_cover_size_as_dag() const {
        MaximumBipartiteMatching bm(this->size());

        REP(i, this->size()) ITR(j, (*this)[i]) {
            bm.add(i, j.to);
        }

        return this->size() - bm.solve();
    }
};

} // namespace Lib


signed main() {
    int n; cin >> n;
    vector<int> s(n), t(n), u(n);
    REP(i, n) cin >> s[i] >> t[i] >> u[i];

    Lib::Graph<> G(n);

    REP(i, n) REP(j, n) {
        if(s[i] <= u[j] and u[j] < t[i]) {
            G.add_edge(i, j);
        }
    }

    cout << G.minimum_paph_cover_size_as_dag() << "\n";
}
