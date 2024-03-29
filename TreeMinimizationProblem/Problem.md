配点：$400$ 点

問題文
=====
$1$ から $N$ までの番号のついた $N$ 個の頂点と，$N-1$ 個の辺からなる，連結な重み付き無向グラフがあります．  

$2 \leq i \leq N$ を満たす任意の整数 $i$ について，頂点 $i$ と頂点 $p_i$ とを結ぶ，重み $w_i$ の辺が存在します．ただし $p_i < i$ です．

また，長さ $Q$ の $2$ 正整数列 $(a_1, a_2, \ldots, a_Q), (b_1, b_2, \ldots, b_Q)$ があり，このとき整数 $k$ に対して $f(k)$ を次のように定めます：
- $f(k) = ($頂点 $a_k$ と頂点 $b_k$ とを結ぶ単純パスに含まれる辺の重みの総和$)$ ．

さらに，任意の重み付きグラフに対して以下の**操作**を行うことができます：

**操作**
- 好きな辺を $1$ つ選択し，その辺の重みを $0$ で置換する．


このグラフに対して，以上の**操作**を $0$ 回以上 $1$ 回以下行うとき，$\displaystyle \sum_{1 \leq k \leq Q} f(k)$ の値は最小でいくつにすることができますか？  
求めてください．  

制約
-----
- $1 \leq \Phi \leq 10^5$
- $1 < N \leq 10^4$
- $\sum_{\phi} \Phi_{\phi}(N) \leq 10^5$
- $1 \leq Q$
- $\sum_{\phi} \Phi_{\phi}(Q) \leq 10^5$
- $1 \leq p_i < i\; \scriptsize (2 \leq i \leq N)$ 
- $|w_i| \leq 10^6 \; \scriptsize (2 \leq i \leq N)$
- $1 \leq a_i < b_i \leq N \; \scriptsize (1 \leq i \leq Q)$  
- 入力はすべて整数

入力
-----
各テストケースの入力は，それぞれ以下の形式で与えられる：
```md
$N$  
$p_2 \enspace w_2$  
$p_3 \enspace w_3$  
$\vdots$  
$p_N \enspace w_N$  
$Q$  
$a_1 \enspace b_1$  
$a_2 \enspace b_2$  
$\vdots$  
$a_Q \enspace b_Q$  

```

出力
-----
答えを出力せよ．  

サンプル
=====
```入力例1
1
9
1 1
2 4
2 3
3 1
3 5
6 1
6 6
6 2
6
3 4
1 5
6 9
2 8
3 9
4 8

```
```出力例1
39

```
$2$ 頂点 $2, 3$ を結ぶ辺に対して操作を $1$ 回行うことが最適です．  

---
```入力例2
1
2
1 -1
3
1 2
1 2
1 2

```
```出力例2
-3

```
