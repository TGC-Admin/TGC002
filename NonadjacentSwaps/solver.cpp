#include <bits/stdc++.h>
using i32 = std::int32_t;
using i64 = std::int64_t;


bool solve(i32 n, std::string s, std::string t) {
    if(s == t) return true;

    if(std::multiset(s.begin(), s.end()) != std::multiset(t.begin(), t.end())) {
        return false;
    }

    if(n <= 2) return false;

    if(n == 3) return s[1] == t[1];

    return true;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::string s, t; std::cin >> s >> t;
        std::cout << (solve(n, s, t) ? "Yes" : "No") << "\n";
    }
}
