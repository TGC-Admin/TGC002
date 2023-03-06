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
    i32 p = 1 << rng(1, 30);
    i32 q = 1 << rng(1, 30);
    REP(i, k-1) {
        d[i] = rng(1, p);
        v[i] = rng(q);
    }
    std::sort(ALL(d));
    d.erase(std::unique(ALL(d)), d.end());
    k = d.size() + 1;

    print(k, t);
    print(0, d);
    print(v.begin(), v.begin()+k-1);

    return 0;
}
