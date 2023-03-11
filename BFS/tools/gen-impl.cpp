/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ GCC */
/* #region template */
#include <bits/stdc++.h>
// using namespace std;

#include "template.hpp"
/* #endregion */

#include "random/generator.hpp"

constexpr i64 K_SUP = 1'000'000'000'000L;

signed main(const int, const char *argv[]) {
    u32 seed = std::stoi(argv[1]);
    lib::random_engine<std::mt19937_64> rng(seed);

    i64 n = std::stoi(argv[2]);

    std::vector<i64> d(n);
    i64 d_sup = n * rng(1, 1050) / 1000;
    REP(i, 1L, n) d[i] = rng(1, std::clamp(d_sup, 1L, n));
    if(rng(2) == 0) REP(i, 1L, std::min(n, d_sup)) d[i] = i;
    std::shuffle(d.begin()+1, d.end(), rng);

    std::unordered_map<i64,i64> cnt(n+1);
    REP(i, n) cnt[d[i]]++;

    i64 k_inf = n-1, k_sup = 0;
    REP(i, n) {
        k_sup += cnt[i] * (cnt[i] - 1) / 2;
        k_sup += cnt[i] * cnt[i+1];
    }
    chmax(k_sup, k_inf);
    // if(k_inf > k_sup) debug(n, d, k_inf, k_sup);

    i64 k = 0;

    int type = rng(8);
    if(type == 0) {
        k = rng(k_inf, k_sup);
    }
    else if(type <= 3) {
        int p = 1 << rng(1, 8);
        k = k_inf + rng(-p, p);
    }
    else if(type <= 6) {
        int p = 1 << rng(1, 8);
        k = k_sup + rng(-p, p);
    }
    else {
        k = rng(1, 1LL << rng(40));
    }
    // debug(type, k_inf, k_sup);
    k = std::clamp(k, 1L, K_SUP);

    print(n, k);
    print(d);

    return 0;
}
