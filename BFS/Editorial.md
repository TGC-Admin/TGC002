# 概要
グラフが構築できることの必要十分条件を考えましょう．

問題原案：kusirakusira

# 解説
まず，グラフは連結である必要がありますから，$\mathrm{mex} \, d > \max \, d$ が必要です．  
以下では一旦この条件を満たすとします．

次に条件を満たすグラフを構築することのできる $M$ の下限と上限を考えます．

### $Ⅰ.$ 下限
条件を満たすグラフの最小構成を考えます．  
これはグラフが木であるときです．
したがって $N-1 \leq M$ が必要です．

### $Ⅱ. $ 上限
条件を満たすグラフの最大構成を考えます．  
最小構成のグラフに最大でどれだけ辺を追加することができるでしょうか？

まず，同じ最短距離を持つ頂点同士は互いに結ぶことができます．  
また，最短距離の差が $1$ であるときも，結ぶことができます．

したがって，次の条件が必要です：
- $M \leq \sum_k \mathrm{comb}(C_k, 2) + \sum_k C_k \cdot C_{k+1}$ 
- ただし以下を満たします：
    - $C_k \coloneqq |\{\, i \mid C_i = k \,\}|$
    - $\displaystyle \mathrm{comb}(n, r) \coloneqq \frac{n!}{r! (n-r)!}$  

---
以上の $3$ つの必要条件の積が十分条件になります．  
これは，$1$ つ目の条件が真のもと，下限以上上限以下の任意の $M$ で条件を満たすグラフが存在することを示すことで証明できます．  


# 実装例
```cpp:C++
#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;


bool solve(const i32 n, const i64 m, std::vector<i32>& d) {
    std::map<i32,i32> cnt;
    for(const auto v : d) cnt[v]++;

    i64 sup = 0;
    for(const auto [ v, c ] : cnt) {
        if(v == 0) continue;
        sup += c * (c - 1) / 2;
        if(not cnt.count(v-1)) return false;
        sup += cnt[v-1] * c;
    }

    return n-1 <= m and m <= sup;
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i64 n, m; std::cin >> n >> m;
        std::vector<i32> d(n); for(auto& v : d) std::cin >> v;
        std::cout << (solve(n, m, d) ? "Yes" : "No") << "\n";
    }
}
```
