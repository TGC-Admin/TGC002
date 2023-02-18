
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int solve(int n, vector<ll>& l) {
    vector<ll> acc_l(n+1, 0);
    inclusive_scan(l.begin(), l.end(), next(acc_l.begin()));

    ll ans = 1;
    for(;n;n--) {
        ll div_size = acc_l[n];

        if(*acc_l.rbegin() % div_size != 0) continue;

        auto div_begin = next(acc_l.begin(), n);
        bool can_div = false;

        while(true) {
            ll nxt = *div_begin + div_size;

            auto itr = lower_bound(div_begin, acc_l.end(), nxt);
            if(*itr != nxt or itr == acc_l.end()) break;

            div_begin = itr;

            if(itr == prev(acc_l.end())) {
                can_div = true;
                break;
            }
        }

        if(can_div) ans = max(ans, *acc_l.rbegin() / div_size);
    }

    return ans;
}

signed main() {
    int $; cin >> $;
    while($--) {
        int n; cin >> n;
        vector<ll> a(n); for(auto& v : a) cin >> v;
        cout << solve(n, a) << "\n";
    }
}
