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
    i32 w_inf = -std::min(1'000'000, 1 << rng(21));
    i32 w_sup = std::min(1'000'000, 1 << rng(21)) + 1;

    i32 type = rng(2);

    std::vector<std::pair<i32,i32>> pw(n);
    REP(i, 1, n) {
        if(i <= 10 or type == 0) {
            pw[i].first = rng(i) + 1;
        }
        else {
            pw[i].first = (i + rng(-10, 0)) / 2 * 2 + i%2;
        }
        pw[i].second = rng(w_inf, w_sup);
    }

    std::vector<std::pair<i32,i32>> ab(q);
    REP(i, q) {
        i32 a = rng(n), b = (a + rng(1, n)) % n;
        if(a > b) std::swap(a, b);
        ab[i] = { a + 1, b + 1 };
    }

    print(n);
    REP(i, 1, n) print(pw[i]);
    print(q);
    REP(i, q) print(ab[i]);

    return 0;
}
