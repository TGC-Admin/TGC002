# 概要
問題特有の性質に着目し，解きやすい形に言い換えて行きましょう．

問題原案：uni_kakurenbo

# 解説

時系列を考えると，コンテスト $i$ が終了して以降に(直/間接的に)コンテスト $j$ に参加できるとき，必ずコンテスト $j$ が終了して以降に(直/間接的に)コンテスト $i$ に**参加することはできない**と分かります．

したがって，$1$ 以上 $N$ 以下の整数を頂点とし，「コンテスト $i$ の終了時にコンテスト $j$ に参加できる」ことを $i \to j$ の有向辺で表現したグラフ $G$ は非循環 (DAG) になります．

$G$ の $i \to j$ の辺の重みを，コンテスト $i$ の終了からコンテスト $j$ が始まるまでの待ち時間 $t_j - u_i$ とすると，この問題は以下のように言い換えることができます．
- $G$ の(重みを無視した)**最小道被覆**の大きさと，その被覆が含む辺の重みの総和の最小値を求めよ．

DAG における最小道被覆問題が，最大二部マッチング問題，すなわち最大流問題に帰着できることは有名ですが，この問題は最小費用流を用いて同様のアプローチで解くことができます．

時間計算量は $O(X^3 \log X)$ などです．

解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

#include <atcoder/mincostflow>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


std::pair<i32,i64> solve(
    const i32 n,
    const std::vector<i32> s,
    const std::vector<i32> t,
    const std::vector<i32> u
) {
    atcoder::mcf_graph<i32,i64> G(2*n+2);

    REP(i, n) REP(j, n) {
        if(s[j] <= u[i] and u[i] <= t[j]) {
            G.add_edge(i, n+j, 1, t[j] - u[i]);
        }
    }

    REP(i, n) {
        G.add_edge(2*n, i, 1, 0);
        G.add_edge(n+i, 2*n+1, 1, 0);
    }

    const auto [ flow, cost ] = G.flow(2*n, 2*n+1);
    return { n - flow, cost };
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::vector<i32> s(n), t(n), u(n);
        REP(i, n) std::cin >> s[i] >> t[i] >> u[i];

        const auto ans = solve(n, s, t, u);
        std::cout << ans.first << " ";
        std::cout << ans.second << "\n";
    }
}

```
