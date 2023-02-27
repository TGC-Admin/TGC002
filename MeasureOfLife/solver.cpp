#include <bits/stdc++.h>
#include <atcoder/modint>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

using mint = atcoder::modint998244353;


signed main() {
    i32 n, k; std::cin >> n >> k;
    std::vector<i32> a(n), b(n);

    REP(i, n) std::cin >> a[i];
    REP(i, n) std::cin >> b[i];

    std::vector dp0(n+2, std::vector<mint>(k+1)), dp1(n+1, std::vector<mint>(k+1));

    dp0[0][0] = dp0[0][1] = 1;

    REP(i, n) {
        dp0[i+1][0] = reduce(dp0[i].begin()+1, dp0[i].end());
        dp1[i+1][0] = reduce(dp1[i].begin()+1, dp1[i].end()) + dp0[i][0] * a[i];
        REPF(j, 1, k) {
            dp0[i+1][j] = dp0[i][j-1];
            dp1[i+1][j] = dp1[i][j-1] - dp0[i][j] * b[i];
        }
    }

    std::cout << reduce(dp1.rbegin()->begin(), dp1.rbegin()->end()).val() << "\n";
}
