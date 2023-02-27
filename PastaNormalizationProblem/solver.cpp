#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;


i32 solve(i32 n, std::vector<i64>& l) {
    std::vector<i64> acc_l(n+1, 0);
    std::inclusive_scan(l.begin(), l.end(), std::next(acc_l.begin()));

    i64 ans = 1;
    for(;n;n--) {
        const i64 div_size = acc_l[n];

        if(*acc_l.rbegin() % div_size != 0) continue;

        auto div_begin = std::next(acc_l.begin(), n);
        bool can_div = false;

        while(true) {
            i64 nxt = *div_begin + div_size;

            auto itr = std::lower_bound(div_begin, acc_l.end(), nxt);
            if(*itr != nxt or itr == acc_l.end()) break;

            div_begin = itr;

            if(itr == std::prev(acc_l.end())) {
                can_div = true;
                break;
            }
        }

        if(can_div) ans = std::max(ans, *acc_l.rbegin() / div_size);
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
