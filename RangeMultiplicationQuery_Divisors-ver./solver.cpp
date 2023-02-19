#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
using ll = long long;

constexpr int PRIMES[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

// 素因数分解
valarray<int> factorize(int x) {
    valarray<int> res(size(PRIMES));
    REP(i, res.size()) {
        int p = PRIMES[i];
        while(x%p == 0) ++res[i], x /= p;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector powers(n+1, valarray<int>(size(PRIMES)));

    vector<int> a(n); REP(i, n) cin >> a[i];

    REP(i, n) {
        auto factors = factorize(a[i]);
        powers[i] += factors, powers[i+1] -= factors;  // imos法 (差分加算)
    }

    int q; cin >> q;
    REP(_, q) {
        int l, r, x; cin >> l >> r >> x; --l;
        auto factors = factorize(x);
        powers[l] += factors, powers[r] -= factors;  // imos法 (差分加算)
    }

    REP(i, n) powers[i+1] += powers[i];  // imos法 (累積)

    transform(
        powers.begin(), powers.end(),
        ostream_iterator<int>(cout, " "),
        [](auto& k) -> ll {
            return std::transform_reduce(begin(k), end(k), 1LL, multiplies<ll>{}, [](int e) -> ll { return e + 1; } );
        }
    );
    cout.seekp(-1) << "\n";
}

signed main() {
    int $; cin >> $;
    while($--) solve();
    return 0;
}
