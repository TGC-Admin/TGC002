# 概要
操作の独立性を考えてみましょう．

問題原案：tnodino

# 解説
**操作**は選ぶ $i$ について独立に行えます．  
したがって，各 $i$ について $A_i$ を $3$ の倍数にする最小手数を求め，それらの総和を求めればよいです．  

**$A_i$ が $3$ の倍数のとき**  
操作の必要はありません．  

**$A_i$ が $3$ の倍数でないとき**  
整数 $k$ を用いて $A_i = 3k + 1$ もしくは $A_i = 3k - 1$ と表せるので，前者ならば $-1$，後者ならば $+1$ を $1$ 回行うことで $3$ の倍数にできます．  

したがって，$A_i$ が $3$ の倍数とならないような $i$ の個数が答えに一致します．  

解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

#include <boost/range/algorithm.hpp>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i64 solve(const i32, const std::vector<i32>& a) {
    return boost::range::count_if(a, [](const i32 v) { return v%3 != 0; });
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::vector<i32> a(n); for(auto& v : a) std::cin >> v;
        std::cout << solve(n, a) << "\n";
    }
}

```
```py:Python
for _ in [0] * int(input()):
    input()
    print(sum(a%3!=0 for a in map(int, input().split())))

```
