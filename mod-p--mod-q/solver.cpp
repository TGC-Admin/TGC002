#include <bits/stdc++.h>
using i32 = std::int32_t;
using i64 = std::int64_t;

i64 solve(i64 p, i64 q, i64 k) {
    if(p > q) std::swap(p, q);
    return (k / std::lcm(p, q)) * q + std::min(q, k % std::lcm(p, q));
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i64 p, q, k; std::cin >> p >> q >> k;
        std::cout << solve(p, q, k) << "\n";
    }
}
