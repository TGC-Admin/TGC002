#include <cstdint>
#include <ios>
#include <iostream>
#include <set>

#include <boost/range/numeric.hpp>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


void solve() {
    i32 q; std::cin >> q;

    std::set<i32> st;

    i32 ans = 0;
    while(q--) {
        i32 t, x; std::cin >> t >> x;
        if(t == 0) {
            st.insert(x);
        }
        if(t == 1) {
            if(not st.count(x)) continue;
            ans++;
        }
    }

    std::cout << ans << "\n";
}

signed main() {
    i32 $; std::cin >> $;
    while($--) solve();
}
