# 概要
考察に詰まったら，手を動かして実験してみましょう．

問題原案：uni_kakurenbo

# 解説
$P \leq Q$ としても一般性は保たれますから，以下は $P \leq Q$ とします．

$x \bmod P < P \leq Q$ より $(x \bmod P) \bmod Q = x \bmod P$ ですから，条件 $x \bmod P = (x \bmod Q) \bmod P$ を満たす $K$ 未満の非負整数 $x$ の個数を求めればよいです．

非負整数 $k$ に対して $kQ \leq x < (k + 1)Q$ の場合を考えます．(これですべての場合を網羅できます)  

$x \bmod Q = x - kQ$ より， $kQ \bmod P = 0$ すなわち $kQ$ が $P$ の倍数であることが必要十分です．  

これは $k$ が $\frac{P}{\gcd \, \{\, P,\,Q \,\}}$ の倍数であると言い換えることができます．  
以上より，周期 $Q\frac{P}{\gcd \, \{\, P,\,Q \,\}} = \mathrm{lcm} \, \{\, P,\,Q \,\}$ ごとに，幅 $Q$ の区間で条件を満たす $x$ が現れるとわかりました．  

したがって答えは $Q \left \lfloor \frac{K}{\mathrm{lcm}\, \{\, P,\,Q \,\}} \right \rfloor + \min \, \{\, Q, K \bmod \mathrm{lcm} \, \{\, P,\,Q \, \} \,\}$ です．

![](https://user-images.githubusercontent.com/64454054/219830253-c129c1a9-587f-4470-9b37-9ecb937ffe86.png)

# 実装例
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll p, ll q, ll k) {
    if(p > q) swap(p, q);
    return (k / lcm(p, q)) * q + min(q, k % lcm(p, q));
}

signed main() {
    int $; cin >> $;
    while($--) {
        ll p, q, k; cin >> p >> q >> k;
        cout << solve(p, q, k) << "\n";
    }
}
```
```py:Python
from math import lcm
for _ in range(int(input())):
    p, q, k = map(int, input().split())
    print((k // lcm(p, q)) * max(p, q) + min(max(p, q), k % lcm(p, q)))
```
