#include <cstdint>
#include <ios>
#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

#include <atcoder/modint>

using i32 = std::int32_t;
using i64 = std::int64_t;
using mint = atcoder::modint998244353;

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


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

    std::vector<i32> a(n, 1);

    i32 q; std::cin >> q;
    REP(_, q) {
        i32 l, r, x; std::cin >> l >> r >> x; --l;
        const auto factors = factorize(x);
        powers[l] += factors, powers[r] -= factors;  // imos法 (差分加算)
    }

    REP(i, n) powers[i+1] += powers[i];  // imos法 (累積)

    std::transform(
        powers.begin(), std::prev(powers.end()),
        std::ostream_iterator<i64>(std::cout, " "),
        [](const auto& k) -> i32 {
            return (
                std::transform_reduce(
                    std::begin(k), std::end(k),
                    mint{1}, std::multiplies<mint>{}, [](const i32 e) -> mint { return e + 1; }
                ).val()
            );
        }
    );
    std::cout << "\n";
}

signed main() {
    i32 $; std::cin >> $;
    while($--) solve();
    return 0;
}
