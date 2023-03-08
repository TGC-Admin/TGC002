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

    std::vector<i64> use;
    REP(rng(1, q << 2)) {
        use.push_back(rng(1'000'000'000L) + 1);
    }

    print(q);
    REP(i, q) {
        i32 t = rng(2);
        i64 x = use[rng(use.size())];

        print(t, x);
    }

    return 0;
}
