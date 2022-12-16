問題文
=====
$N$ 個の頂点と $N-1$ 個の頂点からなる連結な重み付き無向グラフがあります．  

$i$ 番目の辺は $2$ 頂点 $u_i, v_i$ を結んでおり，はじめ，重みは $w_i$ です．  

ここで，長さ $Q$ の $2$ 正整数列 $(a_1, a_2, \ldots, a_Q), (b_1, b_2, \ldots, b_Q)$ に対して，$f(k)$ を次のように定めます：
- $f(k) = (2$ 頂点 $a_k, b_k$ を結ぶパスに含まれる辺の重みの総和$)$


さらに，以下の**操作**を $0$ 回以上 $1$ 回以下行うことができます：

**操作**
- 好きな辺を $1$ つ選択し，その辺の重みを $0$ で置換する


適切に操作を行うとき，$\displaystyle \sum_{1 \leq k \leq Q} f(k)$ の値は最小でいくつにすることができますか？  
求めてください．  

制約
-----
- $1 \leq N, Q \leq 2 \times 10^5$
- $1 \leq u_i, v_i \leq N \; \scriptsize (1 \leq i < N)$ 
- $1 \leq a_i, b_i \leq N \; \scriptsize (1 \leq i \leq Q)$ 
- 入力はすべて整数である

入力
-----
入力は以下の形式で標準入力から与えられる．
```md
$N$  
$u_1 \enspace v_1 \enspace w_1$
```

$N$  
$u_1 \enspace v_1 \enspace w_1$  
$u_2 \enspace v_2 \enspace w_2$  
$\vdots$  
$u_{N-1} \enspace v_{N-1} \enspace w_{N-1}$  
$Q$  
$a_1 \enspace b_1$  
$a_2 \enspace b_2$  
$\vdots$  
$a_Q \enspace b_Q$  


出力
-----
答えを出力せよ．  

サンプル
=====
```入力例1

```
```出力例1

```