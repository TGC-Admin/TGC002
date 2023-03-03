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
    i32 type = std::stoi(argv[3]);

    std::cout << n << "\n";

    std::string s, t;
    REP(n) s += rng('a', 'z'+1);

    if(type == 0) {
        REP(n) t += rng('a', 'z'+1);
    }
    if(type == 1) {
        t = s;
        std::shuffle(ALL(t), rng);
    }

    std::cout << s << "\n" << t << "\n";

    return 0;
}
