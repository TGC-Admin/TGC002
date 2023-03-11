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

    i32 p = 1 << rng(31);
    i32 q = 1 << rng(31);

    std::vector<i32> a(n);
    REP(i, n) a[i] = rng(-q+1, p);

    print(n);
    print(a);

    return 0;
}
