#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
    ll n; cin >> n; ++n;

    ll p = 1, ans = 0;
    while((p <<= 1) <= n) ans += n / p;

    cout << ans << "\n";
}
