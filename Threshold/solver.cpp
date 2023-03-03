#include <bits/stdc++.h>

using i32 = std::int32_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i32 solve(i32, const i32 k, const std::vector<i32>& a) {
    std::sort(a.begin(), a.end());

    std::ptrdiff_t ans = 0;

    auto r = a.begin();
    for(auto l=a.begin(); l<a.end(); ++l) {
        while(r != a.end() and *r - *l <= 2*k) r++;
        ans = std::max(ans, r - l);
    }

    return ans;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n, k; std::cin >> n >> k;
        std::vector<i32> a(n); for(auto& v : a) std::cin >> v;
        std::cout << solve(n, k, a) << "\n";
    }
}
