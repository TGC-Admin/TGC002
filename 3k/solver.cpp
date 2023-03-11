#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

#include <boost/range/algorithm.hpp>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i64 solve(const i32, const std::vector<i32>& a) {
    return boost::range::count_if(a, [](const i32 v) { return v%3 != 0; });
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::vector<i32> a(n); for(auto& v : a) std::cin >> v;
        std::cout << solve(n, a) << "\n";
    }
}
