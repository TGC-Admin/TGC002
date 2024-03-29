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
    lib::random_engine<std::mt19937> rng(seed);

    i32 n = std::stoi(argv[2]);
    i32 k = std::stoi(argv[3]);
    i32 inf = -std::pow(10, rng(0, 10));
    i32 sup = std::pow(10, rng(0, 10)) + 1;

    std::cout << n << " " << k << "\n";

    std::vector<i32> a(n);
    REP(i, n) a[i] = rng(inf, sup);

    print(a);

    return 0;
}
