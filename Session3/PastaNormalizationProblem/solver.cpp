#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)

using ll = long long;

signed main() {
    int n; cin >> n;
    vector<ll> l(n), acc_l(n+1);
    REP(i, n) {
        cin >> l[i];
        acc_l[i+1] = acc_l[i] + l[i];
    }

    int ans = 0;
    REP(i, n) {
        ll div_size = acc_l[i+1];

        if(*acc_l.rbegin() % div_size != 0) continue;

        auto div_begin = next(acc_l.begin(), i+1);
        bool can_div = false;

        while(true) {
            int nxt = div_size + *div_begin;

            auto itr = lower_bound(div_begin, acc_l.end(), nxt);
            if(*itr != nxt or itr == acc_l.end()) break;

            div_begin = itr;

            if(itr != prev(acc_l.end())) continue;

            can_div = true;
            break;
        }

        if(can_div) ans = max(ans, int(*acc_l.rbegin() / div_size));
    }

    cout << ans << "\n";
}
