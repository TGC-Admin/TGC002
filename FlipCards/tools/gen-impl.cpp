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

signed main(const int, const char *argv[]) {
    u32 seed = std::stoi(argv[1]);
    lib::random_engine<std::mt19937_64> rng(seed);

    i32 n = std::stoi(argv[2]);
    i32 k = std::stoi(argv[3]);

    std::vector<i32> a(n), b(n);
    i32 sup_a = 1 << rng(31);
    i32 sup_b = 1 << rng(31);
    REP(i, n) a[i] = rng(sup_a);
    REP(i, n) b[i] = rng(sup_b);

    print(n, k);

    print(a);
    print(b);

    return 0;
}
