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

    i32 k = std::stoi(argv[2]);
    i32 t = rng(1, 1 << rng(31));

    std::vector<i32> d(k-1), v(k-1);
    i32 p = (1 << rng(std::log2(k)-1, 30)) / k;
    i32 q = (1 << rng(std::log2(k)-1, 30)) / k;
    REP(i, k-1) {
        d[i] = rng(p) + 1;
        v[i] = rng(q);
    }

    print(k, t);
    print(d);
    print(v);

    return 0;
}
