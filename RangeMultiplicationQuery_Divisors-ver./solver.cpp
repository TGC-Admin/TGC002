#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)

constexpr i32 PRIMES[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

// 素因数分解
std::valarray<i32> factorize(i32 x) {
    std::valarray<i32> res(std::size(PRIMES));
    REP(i, res.size()) {
        const i32 p = PRIMES[i];
        while(x%p == 0) ++res[i], x /= p;
    }
    return res;
}

void solve() {
    i32 n; std::cin >> n;
    std::vector powers(n+1, std::valarray<i32>(std::size(PRIMES)));

    std::vector<i32> a(n); REP(i, n) std::cin >> a[i];

    REP(i, n) {
        const auto factors = factorize(a[i]);
        powers[i] += factors, powers[i+1] -= factors;  // imos法 (差分加算)
    }

    i32 q; std::cin >> q;
    REP(_, q) {
        i32 l, r, x; std::cin >> l >> r >> x; --l;
        const auto factors = factorize(x);
        powers[l] += factors, powers[r] -= factors;  // imos法 (差分加算)
    }

    REP(i, n) powers[i+1] += powers[i];  // imos法 (累積)

    std::transform(
        powers.begin(), powers.end(),
        std::ostream_iterator<i32>(std::cout, " "),
        [](const auto& k) -> i64 {
            return (
                std::transform_reduce(
                    std::begin(k), std::end(k), 1LL,
                    std::multiplies<i64>{}, [](const i32 e) -> i64 { return e + 1; }
                )
            );
        }
    );
    std::cout.seekp(-1) << "\n";
}

signed main() {
    i32 $; std::cin >> $;
    while($--) solve();
    return 0;
}
