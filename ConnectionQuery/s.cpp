#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(int i = 0; i < (int)(n); ++i)
#define rep2(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep3(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep4(i, a, b, c) for(int i = (a); i < (int)(b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()
#define Sort(a) sort(a.begin(), a.end())
#define RSort(a) sort(a.rbegin(), a.rend())

typedef long long int ll;
typedef unsigned long long ul;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<string> vst;
typedef vector<double> vd;
typedef vector<long double> vld;
typedef pair<long long, long long> P;

template<class T> long long sum(const T& a){ return accumulate(a.begin(), a.end(), 0LL); }
template<class T> auto min(const T& a){ return *min_element(a.begin(), a.end()); }
template<class T> auto max(const T& a){ return *max_element(a.begin(), a.end()); }

const long long MINF = 0x7fffffffffff;
const long long INF = 0x1fffffffffffffff;
const long long MOD = 998244353;
const long double EPS = 1e-9;
const long double PI = acos(-1);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p){ is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){ os << "(" << p.first << ", " << p.second << ")"; return os; }
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for(T &in : v) is >> in; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v){ for(int i = 0; i < (int) v.size(); ++i){ os << v[i] << (i + 1 != (int) v.size() ? " " : ""); } return os; }
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp){ for(auto &[key, val] : mp){ os << key << ":" << val << " "; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &st){ auto itr = st.begin(); for(int i = 0; i < (int)st.size(); ++i){ os << *itr << (i + 1 != (int)st.size() ? " " : ""); itr++; } return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &st){ auto itr = st.begin(); for(int i = 0; i < (int)st.size(); ++i){ os << *itr << (i + 1 != (int)st.size() ? " " : ""); itr++; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> q){ while(q.size()){ os << q.front() << " "; q.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, deque<T> q){ while(q.size()){ os << q.front() << " "; q.pop_front(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> st){ while(st.size()){ os << st.top() << " "; st.pop(); } return os; }
template <class T, class Container, class Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq){ while(pq.size()){ os << pq.top() << " "; pq.pop(); } return os; }

template<class T, class U> inline T vin(T& vec, U n) { vec.resize(n); for(int i = 0; i < (int) n; ++i) cin >> vec[i]; return vec; }
template<class T> inline void vout(T vec, string s = "\n"){ for(auto x : vec) cout << x << s; }
template<class... T> void in(T&... a){ (cin >> ... >> a); }
void out(){ cout << '\n'; }
template<class T, class... Ts> void out(const T& a, const Ts&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T, class U> void inGraph(vector<vector<T>>& G, U n, U m, bool directed = false){ G.resize(n); for(int i = 0; i < m; ++i){ int a, b; cin >> a >> b; a--, b--; G[a].push_back(b); if(!directed) G[b].push_back(a); } }

template <typename T>
struct DynamicUnionFind{
    unordered_map<T, T> par, siz;

    DynamicUnionFind(){
    }

    void init(const T &x){
        par[x] = x;
        siz[x] = 1;
    }

    T root(const T &x){
        if(par.find(x) == par.end()){
            init(x);
        }
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(const T &x, const T &y){
        if(par.find(x) == par.end()){
            init(x);
        }
        if(par.find(y) == par.end()){
            init(y);
        }
        int rx = root(x);
        int ry = root(y);
        if(size(rx) < size(ry)) swap(rx, ry);
        par[rx] = ry;
        siz[ry] += siz[rx];
    }

    bool same(const T &x, const T &y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    T size(const T &x){
        if(par.find(x) == par.end()){
            init(x);
        }
        return siz[root(x)];
    }
};

template <typename T>
struct compress{
    vector<T> sorted, compressed;

    compress(const vector<T>& vec){
        int n = vec.size();
        compressed.resize(n);
        for(T x : vec){
            sorted.push_back(x);
        }
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        for(int i = 0; i < n; i++){
            compressed[i] = lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();
        }
    }

    int get(const T& x) const{
        return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    }

    T inv(const T& x){
        return sorted[x];
    }

    size_t size() const{
        return sorted.size();
    }

    vector<T> getCompressed() const{
        return compressed;
    }
};

template <typename T>
struct BinaryIndexedTree{
    int N;
    vector<T> BIT;
    BinaryIndexedTree(const int &N): N(N), BIT(N + 1, 0){
    }

    T get(int i){
        return sum(i + 1) - sum(i);
    }

    void add(int i, T x){
        i++;
        while(i <= N){
            BIT[i] += x;
            i += i & -i;
        }
    }

    T sum(int i) const {
        T ans = 0;
        while(i > 0){
            ans += BIT[i];
            i -= i & -i;
        }
        return ans;
    }

    T sum(int L, int R) const {
        return sum(R) - sum(L);
    }

    int lower_bound(T x) const {
        if(x <= 0){
            return 0;
        }else{
            int v = 0, r = 1;
            while(r < N) r = r << 1;
            for(int len = r; len > 0; len = len >> 1){
                if(v + len < N && BIT[v + len] < x){
                    x -= BIT[v + len];
                    v += len;
                }
            }
            return v;
        }
    }

    int upper_bound(T x) const {
        if(x < 0){
            return 0;
        }else{
            int v = 0, r = 1;
            while(r <= N) r = r << 1;
            for(int len = r; len > 0; len = len >> 1){
                if(v + len <= N && BIT[v + len] <= x){
                    x -= BIT[v + len];
                    v += len;
                }
            }
            return v;
        }
    }
};

ll t;

void input(){
    in(t);
}

void solve(){
    ll q; in(q);
    vector<tuple<ll, ll, ll>> query;
    vll a;
    rep(i, q){
        ll t, x, y; in(t, x, y);
        a.push_back(x);
        a.push_back(y);
        query.emplace_back(t, x, y);
    }
    compress<ll> comp(a);
    ll n = comp.size();
    DynamicUnionFind<ll> uf;
    BinaryIndexedTree<ll> BIT(n + 1);
    rep(i, n) BIT.add(i, 1);
    rep(i, q){
        auto [t, x, y] = query[i];
        ll x2 = comp.get(x), y2 = comp.get(y);
        ll x3 = BIT.sum(0, x2 + 1), y3 = BIT.sum(0, y2 + 1);
        if(t == 0){
            uf.unite(x3, y3);
        }else if(t == 1){
            BIT.add(x2, n);
            BIT.add(y2 + 1, -n);
        }else{
            if(uf.same(x3, y3)){
                out("Yes");
            }else{
                out("No");
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    input();
    while(t--) solve();
}
