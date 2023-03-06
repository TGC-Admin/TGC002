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
    i32 type = std::stoi(argv[4]);
    i32 t_bind = std::stoi(argv[5]);

    if(q < 0) q = rng(1, 100'000 + 1);
    if(sup_xy < 0) sup_xy = 100'000;

    i32 c = rng(10, 100);
    std::map<i32,i32> id;
    REP(i, c) id[i] = rng(1, 100'000);

    std::cout << q << ln;
    REP(i, q) {
        i32 t = rng(21);
        if(t < 10) t = 0;
        else if(t < 20) t = 2;
        else t = 1;

        if(t_bind >= 0) t = t_bind;

        if(i%100 == 0) t = 2;

        i32 x = -1, y = -1;
        if(type == 0) {
            do {
                x = id[rng(c)], y = id[rng(c)];
            } while(x == y);
        }
        if(type == 1) {
            do {
                x = rng(std::min(100, sup_xy)), y = rng(std::max(0, sup_xy - 100), sup_xy);
            } while(x == y);
        }
        if(x > y) std::swap(x, y);

        std::cout << t << " ";
        std::cout << x << " " << y << ln;
    }

    return 0;
}
