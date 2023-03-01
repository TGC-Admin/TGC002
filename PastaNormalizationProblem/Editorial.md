# 概要
全探索をベースに，効率的に答えを求める工夫をしてみましょう．

問題原案：uni_kakurenbo

# 解説
分割の方法は，正確に $2^{N-1}$ 通りありますから，これらを全て試すことはできません．  
「明らかに不可能な分割方法」とはどのようなものでしょうか？

視点を変えて，$1$ 本目の中パスタを構成する小パスタを固定することを考えてみます．  
左からみて $1$ 以上 $D_1$ 以下の位置にある小パスタを用いて $1$ 本目の中パスタを構成するとします．  
すると，その中パスタの長さ $H_1 = \displaystyle \sum_{1 \leq i \leq D_1} L_i$ は一意に定まります．  

中パスタの長さは全て等しくなくてはなりませんから，$1$ 本目の長さが決まれば，全てのその長さになるように他の中パスタを前から順番に構成していくことを試せます．  
この操作で全ての小パスタを中パスタにすることができれば，そのときに限り可能です．

これは，[ABC265-D](https://atcoder.jp/contests/abc265/tasks/abc265_d) のように累積和と二分探索を用いることで $O(N \log N)$ 時間で可能です．$(A > 0)$

なお，$H_1$ が $\sum L$ の約数でなければ明らかに分割は不可能ですから，その場合を無視することで，より計算量を削減できます．

解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;


i32 solve(i32 n, std::vector<i64>& l) {
    std::vector<i64> acc_l(n+1, 0);
    std::inclusive_scan(l.begin(), l.end(), std::next(acc_l.begin()));

    i64 ans = 1;
    for(;n;n--) {
        const i64 div_size = acc_l[n];

        if(*acc_l.rbegin() % div_size != 0) continue;

        auto div_begin = std::next(acc_l.begin(), n);
        bool can_div = false;

        while(true) {
            i64 nxt = *div_begin + div_size;

            auto itr = std::lower_bound(div_begin, acc_l.end(), nxt);
            if(*itr != nxt or itr == acc_l.end()) break;

            div_begin = itr;

            if(itr == std::prev(acc_l.end())) {
                can_div = true;
                break;
            }
        }

        if(can_div) ans = std::max(ans, *acc_l.rbegin() / div_size);
    }

    return ans;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::vector<i64> a(n); for(auto& v : a) std::cin >> v;
        std::cout << solve(n, a) << "\n";
    }
}

```
