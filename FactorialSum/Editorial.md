# 概要
考察に詰まったら，手を動かして実験してみましょう．

問題原案：uni_kakurenbo

# 解説
$k \cdot k!$ に注目します．  

$(k+1)!$ に形がよく似ています．  
これらの差分を考えてみましょう．  

$(k+1)! - k \cdot k! = ((\cancel k+1) \cancel{- k}) \cdot k! = k!$

$k \cdot k! = (k+1)! - k!$ と分かりました．

したがって，  
$\displaystyle f(n) \\ = \sum_{1 \leq k \leq n} (k \cdot k!) + 1 \\ = \sum_{1 \leq k \leq n}((k+1)! - k!) + 1 \\ = (\cancel{2!} - 1!) + (\cancel{3!} \cancel {- 2!}) + \cdots + ((n+1)! \cancel{- n!}) + 1 \\ = ((n+1)! \cancel{- 1!}) \cancel{+ 1} \\ = (n+1)!$  
です．  

よって「$(n+1)!$ が $2^p$ の倍数となる最大の $p$ を求めよ」という問題を解けばよいです．  
これは**ルジャンドルの定理**を用いると $\Theta(\log N)$ 時間で可能です．  


# 実装例
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll n) {
    n++;

    ll p = 1, ans = 0;
    while((p <<= 1) <= n) ans += n / p;

    return ans;
}

signed main() {
    int $; cin >> $;
    while($--) {
        ll n; cin >> n;
        cout << solve(n) << "\n";
    }
}

```
