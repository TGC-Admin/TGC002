# 概要
問題の条件を整理して簡単にしてみましょう．

問題原案：uni_kakurenbo

# 解説
整数 $a$ についての条件 $|a - x| \leq K$ を考えます．

数直線をイメージするとよいです．  
これは，$x$ を中央とした幅が $2K$ の閉区間に $a$ が含まれることと等しいです．  

![](https://user-images.githubusercontent.com/64454054/219830271-7dbef448-64bf-42bd-b8da-6cadfed8d3cb.png)

整数 $l$ に対して， $l \leq i < r$ なる任意の整数 $i$ について $A_i$ が上記の条件を満たすような最大の整数 $r$ を $R_l$ とします．  

$A = (A_1, A_2, \ldots, A_N)$ を昇順に並び替えると，$R_l$ は $l$ に関して広義単調増加となりますから，**尺取り法**の要領で $l$ の昇順に $R_l$ を求めることができます．  

このとき，$R_l - l$ の最大値が答えです．

# 実装例
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i!=i##_last; ++i)

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(n); REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    ptrdiff_t ans = 0;
    auto r = a.begin();
    REPF(l, a.begin(), a.end()) {
        while(r != a.end() and *r - *l <= 2*k) r++;
        ans = max(ans, r - l);
    }

    cout << ans << "\n";
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
