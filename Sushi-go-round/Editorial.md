# 概要
いろとくんの行動を高速にシミュレートする方法を考えてみましょう．

問題原案：machoniump

# 解説

$R_x \coloneqq (A_i = x$ なる $i)$ とします．  

食べたいお寿司は順に台座 $R_0, R_1, R_2, \ldots, R_{N-1}$ に置かれて流れてきます．  
$R_i < R_{i-1} \; \scriptsize (0 < i < N)$ となったとき，レーンが新たに $1$ 周するのを待たなければならないので，このような $i$ の個数が答えに一致します．  

解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

#include <boost/range/algorithm.hpp>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i32 solve(const i32 n, const std::vector<i32>& p) {
    std::vector<i32> inv(n);
    REP(i, n) inv[p[i]] = i;

    i32 ans = 0;
    REP(i, n-1) ans += inv[i+1] < inv[i];

    return ans;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::vector<i32> p(n); REP(i, n) std::cin >> p[i];
        std::cout << solve(n, p) << "\n";
    }
}

```

```py:Python
for _ in [0] * int(input()):
    n = int(input())
    A = map(int, input().split())
    rev = [0] * n
    for i, a in enumerate(A): rev[a] = i
    ans = 0
    for i in range(n-1):
        ans += rev[i+1] < rev[i]
    print(ans)

```
