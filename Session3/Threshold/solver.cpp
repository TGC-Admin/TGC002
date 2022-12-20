#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i!=i##_last; ++i)

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "\033[3;35m#" + to_string(__LINE__) + "\033[m  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) ({ ; })
    #define DEBUG(...) ({ ; })
#endif

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(n); REP(i, n) cin >> a[i];

    map<int,int> cnt;
    REP(i, n) ++cnt[a[i]];

    auto l = cnt.begin();
    int ans = 0, pro_ans = 0;
    REPF(r, cnt.begin(), cnt.end()) {
        pro_ans += r->second;
        while(r->first - l->first > 2*k) pro_ans -= (l++)->second;
        ans = max(ans, pro_ans);
    }

    cout << ans << "\n";
}
