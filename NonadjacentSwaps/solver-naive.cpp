#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

bool solve(int n, string s, string t) {
    queue<string> que;
    unordered_set<string> seen;

    que.push(s), seen.insert(s);

    while(not que.empty()) {
        auto v = que.front(); que.pop();
        if(v == t) return true;
        REP(i, n) REPF(j, i+2, n) {
            swap(v[i], v[j]);
            if(seen.count(v)) continue;
            seen.insert(v);
            que.push(v);
            swap(v[i], v[j]);
        }
    }

    return false;
}

signed main() {
    int $; cin >> $;
    while($--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        cout << (solve(n, s, t) ? "Yes" : "No") << "\n";
    }
}
