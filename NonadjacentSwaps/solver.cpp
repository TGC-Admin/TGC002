#include <bits/stdc++.h>
using namespace std;

bool solve(int n, string s, string t) {
    if(s == t) return true;

    if(multiset(s.begin(), s.end()) != multiset(t.begin(), t.end())) {
        return false;
    }

    if(n <= 2) return false;

    if(n == 3) return s[1] == t[1];

    return true;
}

signed main() {
    int $; cin >> $;
    while($--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        cout << (solve(n, s, t) ? "Yes" : "No") << "\n";
    }
}
