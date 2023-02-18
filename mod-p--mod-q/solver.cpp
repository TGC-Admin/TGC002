#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll p, ll q, ll k) {
    if(p > q) swap(p, q);
    return (k / lcm(p, q)) * q + min(q, k % lcm(p, q));
}

signed main() {
    int $; cin >> $;
    while($--) {
        ll p, q, k; cin >> p >> q >> k;
        cout << solve(p, q, k) << "\n";
    }
}
