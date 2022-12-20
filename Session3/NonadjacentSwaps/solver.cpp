#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

signed main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    if(set(s.begin(), s.end()) != set(t.begin(), t.end())) {
        cout << "No\n";
        return 0;
    }

    if(n >= 4) {
        cout << "Yes\n";
        return 0;
    }

    queue<string> que;
    unordered_set<string> seen;;

    que.push(s), seen.insert(s);

    while(!que.empty()) {
        auto v = que.front(); que.pop();
        if(v == t) {
            cout << "Yes\n";
            return 0;
        }
        REP(i, n) REPF(j, i+2, n) {
            swap(v[i], v[j]);
            if(seen.count(v)) continue;
            seen.insert(v);
            que.push(v);
            swap(v[i], v[j]);
        }
    }

    cout << "No\n" << "\n";
}
