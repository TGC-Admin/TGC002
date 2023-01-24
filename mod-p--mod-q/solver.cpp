#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long p, q, k; cin >> p >> q >> k;
    if(p > q) swap(p, q);

    cout << (k / lcm(p, q)) * q + min(q, k % lcm(p, q)) << "\n";
}
