# 概要
動的計画法を用いて解くことのできる典型的な問題の例です．  
少し複雑ですが，状態を丁寧に整理して漸化式を導いてください．

問題原案：uni_kakurenbo

# 解説
動的計画法を用いて解くことができます．  
その一例を紹介します．

$2$ 数列 $A, B$ はいずれも 0-based indexing とします．

- 定義  
    - $\mathrm{DP_0}(i,j) \coloneqq ($先頭 $i+1$ 枚目までの裏返し方で，末尾に裏を向いたカードが $j$ 個連続するようなものの総数$)$
    - $\mathrm{DP_1}(i,j) \coloneqq ($先頭 $i$ 枚目までの裏返し方で，末尾に裏を向いたカードが $j$ 個連続するようなものスコアの総和$)$

- 初期状態：
    - $\mathrm{DP_0}(0,0) = \mathrm{DP_0}(0,1) = 1$  
    - それ以外はすべて $0$．


- 遷移：
    - $\text{For} \;\,i \gets [\, 0, 1, \ldots, N\,):$
        - $\mathrm{DP_0}(i+1, 0) \gets \sum\, \{\, \mathrm{DP_0}(i,j) \mid 1 \leq j < k \,\}$　#任意の枚数裏が連続 → 表
        - $\mathrm{DP_1}(i+1, 0) \gets \sum\, \{\, \mathrm{DP_1}(i, j) \mid 1 \leq j < k \,\} + \mathrm{DP_0}(i,0) \cdot A_i$
        - $\text{For} \;\,j \gets [\, 1, 2, \ldots, K\,):$
            - $\mathrm{DP_0}(i+1, j) \gets \mathrm{DP_0}(i, j-1)$　# $j$ 枚裏が連続 → $j+1$ 枚裏が連続
            - $\mathrm{DP_1}(i+1, j) \gets \mathrm{DP_1}(i, j-1) + \mathrm{DP_0}(i, j) \cdot B_i$

- 結果：
    - $\sum_k \,\mathrm{DP_1}(N, k) $

解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <bits/stdc++.h>
#include <atcoder/modint>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

using mint = atcoder::modint998244353;

mint solve(const i32 n, const i32 k, const std::vector<i32>& a, const std::vector<i32>& b) {
std::vector dp0(n+1, std::vector<mint>(k+1)), dp1(n+1, std::vector<mint>(k+1));

    dp0[0][0] = dp0[0][1] = 1;

    REP(i, n) {
        dp0[i+1][0] = std::reduce(std::next(dp0[i].begin()), dp0[i].end());
        dp1[i+1][0] = std::reduce(std::next(dp1[i].begin()), dp1[i].end()) + dp0[i][0] * a[i];
        REPF(j, 1, k) {
            dp0[i+1][j] = dp0[i][j-1];
            dp1[i+1][j] = dp1[i][j-1] + dp0[i][j] * b[i];
        }
    }

    return std::reduce(dp1[n].begin(), dp1[n].end());
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n, k; std::cin >> n >> k;
        std::vector<i32> a(n), b(n);
        REP(i, n) std::cin >> a[i];
        REP(i, n) std::cin >> b[i];
        std::cout << solve(n, k, a, b).val() << "\n";
    }
}

```
