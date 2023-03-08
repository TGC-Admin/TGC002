# 概要
全探索をベースに，効率的に答えを求める工夫をしてみましょう．

問題原案：uni_kakurenbo

# 解説
分割の方法は，正確に $2^{N-1}$ 通りありますから，これらを全て試すことはできません．  

視点を変えて，$1$ 本目の中パスタを構成する小パスタを固定することを考えてみます．  
左からみて $1$ 以上 $D_1$ 以下の位置にある小パスタを用いて $1$ 本目の中パスタを構成するとします．  
すると，その中パスタの長さ $H_1 = \displaystyle \sum_{1 \leq i \leq D_1} L_i$ は一意に定まります．  

$H_1$ が $\sum L$ の約数でなければ，分割は明らかに不可能です．

また，中パスタの長さは全て等しくなくてはなりませんから，$1$ 本目の長さが決まれば，全てのその長さになるように他の中パスタを前から順番に構成していくことを試せます．  
この操作で全ての小パスタを中パスタにすることができれば，そのときに限り可能です．  
これは $O(N)$ 時間で行うことができます．

約数の個数のオーダーを考えると，このアルゴリズム全体としての時間計算量は $O(N \sqrt{\sum L})$ と見積れます．  
なお，$\sum L$ 約数の個数は，実際には $\sqrt {\sum L}$ よりもずっと少ないです．


解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i32 solve(i32 n, const std::vector<i64>& l) {
    std::vector<i64> s = { 0 };
    std::inclusive_scan(l.begin(), l.end(), std::back_inserter(s));

    i64 ans = 1;
    for(;n;n--) {
        const i64 div_size = s[n];

        if(s.back() % div_size != 0) continue;

        auto div_begin = std::next(s.begin(), n);
        bool can_div = false;

        while(true) {
            i64 nxt = *div_begin + div_size;

            auto itr = std::lower_bound(div_begin, s.end(), nxt);
            if(*itr != nxt or itr == s.end()) break;

            div_begin = itr;

            if(itr == std::prev(s.end())) {
                can_div = true;
                break;
            }
        }

        if(can_div) ans = std::max(ans, s.back() / div_size);
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
