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
    print(n);

    i32 p = 1 << rng(3, 31);

    REP(i, n) {
        std::set<i32> stu;
        do {
            stu = { (i32)rng(p), (i32)rng(p), (i32)rng(p) };
        } while(stu.size() != 3);

        print(stu);
    }

    return 0;
}
