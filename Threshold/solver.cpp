#include <bits/stdc++.h>
using namespace std;

int solve(int, int k, vector<int>& a) {
    sort(a.begin(), a.end());

    ptrdiff_t ans = 0;

    auto r = a.begin();
    for(auto l=a.begin(); l<a.end(); ++l) {
        while(r != a.end() and *r - *l <= 2*k) r++;
        ans = max(ans, r - l);
    }

    return ans;
}

signed main() {
    int $; cin >> $;
    while($--) {
        int n, k; cin >> n >> k;
        vector<int> a(n); for(auto& v : a) cin >> v;
        cout << solve(n, k, a) << "\n";
    }
}
