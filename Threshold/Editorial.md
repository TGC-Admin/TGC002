# 概要
問題の条件を整理して簡単にしてみましょう．

問題原案：uni_kakurenbo

# 解説
整数 $a$ についての条件 $|a - x| \leq K$ を考えます．

数直線をイメージするとよいです．  
これは，$x$ を中央とした幅が $2K$ の閉区間に $a$ が含まれることと等しいです．  

![](https://user-images.githubusercontent.com/64454054/219830271-7dbef448-64bf-42bd-b8da-6cadfed8d3cb.png)

整数 $l$ に対して， $l \leq i < r$ なる任意の整数 $i$ について $A_i$ が上記の条件を満たすような $x$ が存在する最大の整数 $r$ を $R_l$ とします．  

$A = (A_1, A_2, \ldots, A_N)$ を昇順に並び替えると，$R_l$ は $l$ に関して広義単調増加となりますから，**尺取り法**の要領で $l$ の昇順に $R_l$ を求めることができます．  

このとき，$R_l - l$ の最大値が答えです．


解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <bits/stdc++.h>

using i32 = std::int32_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i32 solve(i32, const i32 k, const std::vector<i32>& a) {
    std::sort(a.begin(), a.end());

    std::ptrdiff_t ans = 0;

    auto r = a.begin();
    for(auto l=a.begin(); l<a.end(); ++l) {
        while(r != a.end() and *r - *l <= 2*k) r++;
        ans = std::max(ans, r - l);
    }

    return ans;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n, k; std::cin >> n >> k;
        std::vector<i32> a(n); for(auto& v : a) std::cin >> v;
        std::cout << solve(n, k, a) << "\n";
    }
}

```

```py:Python
def solve():
    n, k = map(int, input().split())
    A = sorted(map(int, input().split()))

    r, ans = 0, 0
    for l in range(n):
        while r != n and A[r] - A[l] <= 2*k:
            r += 1
        ans = max(ans, r - l)

    print(ans)

for _ in range(int(input())):
    solve()
```
