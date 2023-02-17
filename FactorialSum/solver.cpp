#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll n) {
    n++;

    ll p = 1, ans = 0;
    while((p <<= 1) <= n) ans += n / p;

    return ans;
}

signed main() {
    int $; cin >> $;
    while($--) {
        ll n; cin >> n;
        cout << solve(n) << "\n";
    }
}
