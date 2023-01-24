#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#include <atcoder/mincostflow>

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define ITR(x,v) for(const auto &x : (v))


signed main() {
    int n; cin >> n;
    vector<int> s(n), t(n), u(n);
    REP(i, n) cin >> s[i] >> t[i] >> u[i];

    atcoder::mcf_graph<int,ll> G(2*n+2);

    REP(i, n) REP(j, n) {
        if(s[j] <= u[i] and u[i] < t[j]) {
            G.add_edge(i, n+j, 1, t[j] - u[i]);
        }
    }

    REP(i, n) {
        G.add_edge(2*n, i, 1, 0);
        G.add_edge(n+i, 2*n+1, 1, 0);
    }

    auto [ flow, cost ] = G.flow(2*n, 2*n+1);

    cout << n - flow << " " << cost << "\n";
}
