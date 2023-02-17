#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
using ll = long long;

constexpr int PRIMES[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
constexpr int P = size(PRIMES);

template<class T> std::map<T,int> factorize(T x) {
    std::map<T,int> res;
    for(T v=2; v*v <= x; ++v) {
        if(x%v != 0) continue;
        while(x%v == 0) ++res[v], x /= v;
    }
    if(x != 1) res[x] = 1;
    return res;
}

void solve() {
    int n; cin >> n;
    vector powers(n+1, valarray<int>(P));

    vector<int> a(n); REP(i, n) cin >> a[i];

    REP(i, n) {
        auto factors = factorize(a[i]);
        REP(j, P) {
            powers[i][j] += factors[PRIMES[j]];
            powers[i+1][j] -= factors[PRIMES[j]];
        }
    }

    int q; cin >> q;
    REP(_, q) {
        int l, r, x; cin >> l >> r >> x; --l;

        auto factors = factorize(x);
        REP(j, P) {
            // imos法 (差分加算)
            powers[l][j] += factors[PRIMES[j]];
            powers[r][j] -= factors[PRIMES[j]];
        }
    }

    // imos法 (累積)
    REP(i, n) powers[i+1] += powers[i];

    REP(i, n) {
        ll ans = 1;
        REP(j, P) ans *= powers[i][j] + 1;
        cout << ans << " ";
    }
    cout << "\n";
}

signed main() {
    int $; cin >> $;
    while($--) solve();
    return 0;
}
