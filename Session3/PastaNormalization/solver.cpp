#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)

using ll = long long;

signed main() {
    int n; cin >> n;
    vector<ll> l(n); REP(i, n) cin >> l[i];

    int ans = 1;

    ll div_num = 0;
    REP(i, n) {
        div_num += l[i];
        int j = i+1, cnt = 1;
        while(true) {
            ll sum = 0;
            while(sum < div_num and j < n) {
                sum += l[j];
                ++j;
            }
            if(sum != div_num) break;
            ++cnt;
            if(j < n) continue;
            ans = max(ans, cnt);
            break;
        }
    }

    cout << ans << "\n";
}
