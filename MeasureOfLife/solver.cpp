#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

#include <atcoder/modint>
using mint = atcoder::modint998244353;

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);

    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];

    vector dp0(n+2, vector<mint>(k+1)), dp1(n+1, vector<mint>(k+1));

    dp0[0][0] = dp0[0][1] = 1;

    REP(i, n) {
        dp0[i+1][0] = reduce(dp0[i].begin()+1, dp0[i].end());
        dp1[i+1][0] = reduce(dp1[i].begin()+1, dp1[i].end()) + dp0[i][0] * a[i];
        REPF(j, 1, k) {
            dp0[i+1][j] = dp0[i][j-1];
            dp1[i+1][j] = dp1[i][j-1] - dp0[i][j] * b[i];
        }
    }

    cout << reduce(dp1.rbegin()->begin(), dp1.rbegin()->end()).val() << "\n";
}
