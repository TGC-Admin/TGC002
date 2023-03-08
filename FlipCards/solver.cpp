#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

#include <boost/range/numeric.hpp>

#include <atcoder/modint>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)
#define FORF(i,l,r) for(auto i=(l), i##_last=(r); i<=i##_last; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

using mint = atcoder::modint998244353;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


mint solve(const i32 n, const i32 k, const std::vector<i32>& a, const std::vector<i32>& b) {
std::vector dp0(n+1, std::vector<mint>(k+1)), dp1(n+1, std::vector<mint>(k+1));
    dp0[0][0] = dp0[0][1] = 1;

    REP(i, n) {
        dp0[i+1][0] = std::reduce(std::next(dp0[i].begin()), dp0[i].end());
        dp1[i+1][0] = std::reduce(std::next(dp1[i].begin()), dp1[i].end()) + dp0[i][0] * a[i];
        FORF(j, 1, k) {
            dp0[i+1][j] = dp0[i][j-1];
            dp1[i+1][j] = dp1[i][j-1] + dp0[i][j] * b[i];
        }
    }

    return boost::accumulate(dp1[n], mint{ 0 });
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n, k; std::cin >> n >> k;
        std::vector<i32> a(n), b(n);
        REP(i, n) std::cin >> a[i];
        REP(i, n) std::cin >> b[i];
        std::cout << solve(n, k, a, b).val() << "\n";
    }
}
