# 概要
複数の典型を組み合わせることが必要となる問題です.  
また，かなりの実装量があり，正確にコーディングすることが求められます．

問題原案：Syntax_Error_

# 解説
[こちら](https://github.com/uni-kakurenbo/TGC002/blob/main/TreeMinimizationProblem/Editorial.md)をご参照ください

解説：Syntax_Error_

# 実装例
```cpp:C++
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;

// {深さ, 頂点番号}
using S = pair<int, int>;
constexpr int inf = 2147483647;
S op(S a, S b) { return min(a, b); }
S e() { return {inf, -1}; }

void solve() {
  // 入力
  int N;
  cin >> N;
  vector<int> w(N);
  vector<vector<int>> G(N);
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p >> w[i];
    G[p - 1].push_back(i);
  }

  // オイラーツアー
  vector<int> in(N, -1);
  vector<S> V;
  int last{};
  auto dfs = [&](auto self, int v, int d) -> void {
    in[v] = last++;
    V.push_back({d, v});
    for (auto&& u : G[v]) {
      self(self, u, d + 1);
      V.push_back({d, v});
      last++;
    }
  };
  dfs(dfs, 0, 0);
  segtree<S, op, e> seg(V);
  int Q;
  cin >> Q;
  vector<long long> c(N);
  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (in[a] > in[b]) swap(a, b);
    int lca = seg.prod(in[a], in[b]).second;
    c[a]++, c[b]++, c[lca] -= 2;
  }

  // いもす法
  auto dfs2 = [&](auto self, int v) -> void {
    for (auto&& u : G[v]) {
      self(self, u);
      c[v] += c[u];
    }
  };
  dfs2(dfs2, 0);
  
  //答えを求める
  // w[0]*c[0]=0を利用して場合分けを回避する
  vector<long long> wc(N);
  for (int i = 0; i < N; i++) wc[i] = w[i] * c[i];
  sort(wc.begin(), wc.end());
  cout << reduce(wc.begin(), wc.end() - 1) << endl;
}

signed main() {
  int $; cin >> $;
  while($--) solve();
}

```
