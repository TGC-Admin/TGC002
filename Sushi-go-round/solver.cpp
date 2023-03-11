#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

#include <boost/range/algorithm.hpp>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i32 solve(const i32 n, const std::vector<i32>& p) {
    std::vector<i32> inv(n);
    REP(i, n) inv[p[i]] = i;

    i32 ans = 0;
    REP(i, n-1) ans += inv[i+1] < inv[i];

    return ans;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::vector<i32> p(n); REP(i, n) std::cin >> p[i];
        std::cout << solve(n, p) << "\n";
    }
}
