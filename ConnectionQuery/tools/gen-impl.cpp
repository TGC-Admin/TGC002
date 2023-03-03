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

    i32 q = std::stoi(argv[2]);
    i32 sup_xy = std::stoi(argv[3]);

    if(q < 0) q = rng(1, 100'000 + 1);
    if(sup_xy < 0) sup_xy = 100'000;

    std::cout << q << ln;
    REP(q) {
        i32 t = rng(3);

        i32 x = rng(sup_xy), y = (x + rng(sup_xy - 1) + 1) % sup_xy;
        if(x > y) std::swap(x, y);

        std::cout << t << " ";
        std::cout << x << " " << y << ln;
    }

    return 0;
}
