配点：$200$ 点

問題文
=====

正の整数 $n$ に対して $f(n)$ を次のように定めます：  
$\displaystyle f(n) \coloneqq \sum_{1 \leq k \leq n} (k \cdot k!) + 1$

正の整数 $N$ について，$f(N)$ が $2^p$ の倍数となるような最大の非負整数 $p$ を求めてください．

ただし，任意の正の整数 $x$ に対して $\displaystyle x! = \prod_{1 \leq k \leq x} k$ を満たします．  

制約
-----
- $1 \leq \Phi \leq 10^5$
- $1 \leq N \leq 2^{60}$
- 入力はすべて整数

入力
-----
各テストケースの入力は，それぞれ以下の形式で与えられる：
```md
$N$

```

出力
-----
答えを出力せよ．  

サンプル
=====
```入力例1
2
3
1

```
```出力例1
3
1

```

$f(3) = (1 \cdot 1! + 2 \cdot 2! + 3 \cdot 3!) + 1 = 24 = 2^3 \cdot 3$ を満たします．
