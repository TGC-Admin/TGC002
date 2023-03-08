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
文字列 `1234` を操作によって `2134`, `1324`, `1243` の $3$ 通りに並べ替えることができるならば，$N \geq 4$ で任意の隣接する $2$ 文字を交換することが可能なので，このとき $S$ を任意に並び変えて $S = T$ とすることができます． (バブルソートなどを考えると明らかです．)

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

解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <cstdint>
#include <ios>
#include <iostream>
#include <string>
#include <set>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


bool solve(const i32 n, const std::string& s, const std::string& t) {
    if(s == t) return true;

    if(std::multiset(s.begin(), s.end()) != std::multiset(t.begin(), t.end())) {
        return false;
    }

    if(n <= 2) return false;

    if(n == 3) return s[1] == t[1];

    return true;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::string s, t; std::cin >> s >> t;
        std::cout << (solve(n, s, t) ? "Yes" : "No") << "\n";
    }
}

```

```py:Python
def solve(n, s, t):
    if s == t:
        return True
    if sorted(s) != sorted(t):
        return False
    if n <= 2:
        return False
    if n == 3:
        return s[1] == t[1]
    return True

for i in [0] * int(input()):
    n = int(input())
    s, t = map(str, input().split())
    print("Yes" if solve(n, s, t) else "No")

```
