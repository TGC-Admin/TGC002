#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;


i32 solve(i32 n, const std::vector<i64>& l) {
    std::vector<i64> s = { 0 };
    std::inclusive_scan(l.begin(), l.end(), std::back_inserter(s));

    i64 ans = 1;
    for(;n;n--) {
        const i64 div_size = s[n];

        if(s.back() % div_size != 0) continue;

        auto div_begin = std::next(s.begin(), n);
        bool can_div = false;

        while(true) {
            i64 nxt = *div_begin + div_size;

            auto itr = std::lower_bound(div_begin, s.end(), nxt);
            if(*itr != nxt or itr == s.end()) break;

            div_begin = itr;

            if(itr == std::prev(s.end())) {
                can_div = true;
                break;
            }
        }

        if(can_div) ans = std::max(ans, s.back() / div_size);
    }

    return ans;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::vector<i64> a(n); for(auto& v : a) std::cin >> v;
        std::cout << solve(n, a) << "\n";
    }
}
