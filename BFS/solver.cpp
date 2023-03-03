#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


bool solve(const i32 n, const i64 m, std::vector<i32>& d) {
    std::map<i32,i32> cnt;
    for(const auto v : d) cnt[v]++;

    i64 sup = 0;
    for(const auto [ v, c ] : cnt) {
        if(v == 0) continue;
        sup += c * (c - 1) / 2;
        if(not cnt.count(v-1)) return false;
        sup += cnt[v-1] * c;
    }

    return n-1 <= m and m <= sup;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i64 n, m; std::cin >> n >> m;
        std::vector<i32> d(n); for(auto& v : d) std::cin >> v;
        std::cout << (solve(n, m, d) ? "Yes" : "No") << "\n";
    }
}
