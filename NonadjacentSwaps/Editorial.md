# 概要
操作を繰り返すことで，文字列を自由に並べ替えることはできるか考えてみましょう．

問題原案：uni_kakurenbo

# 解説

まず， $S = T$ のとき明らかに `Yes` です．  
また，$S$ と $T$ とに含まれている文字とそれらの個数が一致していない場合，`No` です．


以下では $S \not= T$ かつ $S$ と $T$ とが含む文字と個数は一致しているものとします．

#### $N \geq 4$ のとき
`Yes` です．  

これは次のように証明できます：  
文字列 `1234` を操作によって `2134`, `1324`, `1243` の $3$ 通りに並べ替えることができるならば，$N \geq 4$ で任意の $2$ 文字を交換することが可能なので，このとき $S$ を任意に並び変えて $S = T$ とすることができます． (バブルソートなどを考えると明らかです．)

- `1234` $\to$ `4231` $\to$ `4132` $\to$ `2134`
- 同様に，`1234` $\to$ `1243`
- 上記を利用して，`1234` $\to$ `2143` $\to$ `3142` $\to$ `1324`  

以上より従います．

#### $N < 4$ のとき
場合分けを行うことで AC を得ることができます：
- $N \leq 2$： `No`  
- $N = 3$：
    - $S_2 = T_2$： `Yes`
    - $S_2 \not= T_2$： `No`  


# 実装例
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

bool solve(int n, string s, string t) {
    if(s == t) return true;

    if(multiset(s.begin(), s.end()) != multiset(t.begin(), t.end())) {
        return false;
    }

    if(n <= 2) return false;

    if(n == 3) return s[1] == t[1];

    return true;
}

signed main() {
    int $; cin >> $;
    while($--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        cout << (solve(n, s, t) ? "Yes" : "No") << "\n";
    }
}

```
