#include <cstdint>
#include <ios>
#include <iostream>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i64 solve(i32 r) {
    return 3L * r * r;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 r; std::cin >> r;
        std::cout << solve(r) << "\n";
    }
}
