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
    i32 q = std::stoi(argv[3]);

    print(n, q);
    REP(q) {
        i32 l = rng(n), r = (rng(n) + l) % n;
        if(r < l) std::swap(l, r);

        i32 x = rng(1, 101);
        print(l+1, r+1, x);
    }

    return 0;
}
