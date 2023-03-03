#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i64 solve(i64 n) {
    n++;

    i64 p = 1, ans = 0;
    while((p <<= 1) <= n) ans += n / p;

    return ans;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i64 n; std::cin >> n;
        std::cout << solve(n) << "\n";
    }
}
