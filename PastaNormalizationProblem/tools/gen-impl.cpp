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
    lib::random_engine<std::mt19937_64> rng(seed);

    i32 n = std::stoi(argv[2]);
    bool type = std::stoi(argv[3]);

  top:
    i32 p = rng(0, 31);
    i64 sup = std::min(100, 1 << p) + 1;

    std::vector<i32> a;
    if(type == 0) {
        a.assign(n, 0);
        REP(i, n) a[i] = rng(1, sup);
    }
    if(type == 1) {
        i64 div_sup = 1000;

        if(rng(1) == 0) chmax(div_sup, sup);
        else chmax(div_sup, sup * n);

        i64 div = rng(10, div_sup);
        while(true) {
            std::vector<i32> b;
            i64 sum = 0;
            do {
                i32 v = rng(1, std::min(div - sum, sup));
                sum += v;
                b.push_back(v);
            } while(sum != div);
            if(a.size() + b.size() > n) break;

            std::shuffle(b.begin(), b.end(), rng);
            std::copy(ALL(b), std::back_inserter(a));
        }
    }
    if(a.size() <= 0) goto top;

    print(a.size());
    print(a);

    return 0;
}
