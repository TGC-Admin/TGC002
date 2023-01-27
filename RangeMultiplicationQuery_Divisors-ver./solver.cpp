#include <bits/stdc++.h>
using namespace std;


#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define FOR(i,l,r) for(auto i=(l), i##_last=(r); i<=i##_last; ++i)

using ll = long long;


template<class T> std::map<T,int> factorize(T x) {
    std::map<T,int> res;
    for(T v=2; v*v <= x; ++v) {
        if(x%v != 0) continue;
        while(x%v == 0) ++res[v], x /= v;
    }
    if(x != 1) res[x] = 1;
    return res;
}

template<class T> std::vector<T> prime_table(const T max) {
    std::vector<char> is_prime(max+1, true);
    std::vector<T> res;

    is_prime[0] = is_prime[1] = false;
    FOR(p, T{2}, max) {
        if(is_prime[p]) {
            for(T v = p*p; v <= max; v += p) is_prime[v] = false;
            res.emplace_back(p);
        }
    }

    return res;
};


signed main() {
    const auto primes = prime_table(100);
    int m = primes.size();

    int n; cin >> n;
    vector powers(n+1, valarray<int>(m));

    vector<int> a(n); REP(i, n) cin >> a[i];
    REP(i, n) {
        auto factors = factorize(a[i]);
        REP(j, m) {
            powers[i][j] += factors[primes[j]];
            powers[i+1][j] -= factors[primes[j]];
        }
    }

    int q; cin >> q;
    REP(_, q) {
        int l, r, x; cin >> l >> r >> x; --l;

        auto factors = factorize(x);
        REP(j, m) {
            powers[l][j] += factors[primes[j]];
            powers[r][j] -= factors[primes[j]];
        }
    }

    REP(i, n) powers[i+1] += powers[i];

    REP(i, n) {
        ll ans = 1;
        REP(j, m) ans *= powers[i][j] + 1;
        std::cout << ans << "\n";
    }

    return 0;
}
