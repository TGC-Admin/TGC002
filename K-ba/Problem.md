配点：$400$ 点

問題文
=====
分岐のない $1$ 本の道のうえに，$1$ から $K$ までの番号のついた，$K$ 個の**場**と呼ばれる地点が順に並んでいます．  
場 $i$ と場 $i+1$ とは $d_i \; \scriptsize \mathrm{[m]}$ 離れています． $\scriptsize (1 \leq i < K)$

MojaMoja 君は現在，既に $10^{100} \; \scriptsize \mathrm{[円]}$ を所持していますが，更に資産を増やしたいと思っています．  
そこで，次のようなゲームに参加することにしました：  
- $1 \leq l < r \leq K$ を満たす $2$ 整数 $l, r$ を選び，馬に乗って場 $l$ から 場 $r$ へ移動する．  
- 馬の走る速さは，はじめ $0 \; \scriptsize \mathrm{[m/秒]}$ であり，$1 \; \scriptsize \mathrm{[円]}$ を支払うごとに $1 \; \scriptsize \mathrm{[m/秒]}$ ずつ速く走れるように改造できる．すなわち，$p \; \scriptsize \mathrm{[円]}$ を払うことで $p \; \scriptsize \mathrm{[m/秒]}$ で走ることができるようになる．( $p$ は非負整数)  
- $T \; \scriptsize \mathrm{[秒]}$ 以内に場 $l$ から場 $r$ へ移動することができれば，ゲームをクリアしたとみなされる．  
- ゲームをクリアしたとき，場 $i$ と場 $i+1$ との間を通過したごとに，報酬として $v_i \; \scriptsize \mathrm{[円]}$ を得る．$\scriptsize (1 \leq i < K)$
- $T \; \scriptsize \mathrm{[秒]}$ 以内に到達できなかった場合の報酬はない．

適切に馬を改造することによって「『報酬として得る金額』から『そのための馬の改造に費やした金額』を引いた差額」(利益) を正とすることができるような $l,r \; \scriptsize (l < r)$ の選び方は何通りあるでしょうか？  
求めてください．

制約
-----
- $1 \leq \Phi \leq 10^5$
- $1 < K$  
- $\sum_{\phi} \Phi_{\phi}(K) \leq 10^6$
- $0 < T < 2^{30}$  
- $0 < d_i \; \scriptsize (1 \leq i < K)$
- $0 \leq v_i \; \scriptsize (1 \leq i < K)$
- $\displaystyle \sum_{1 \leq i < K} d_i, \displaystyle \sum_{1 \leq i < K} v_i < 2^{30}$
- 入力はすべて整数

入力
-----
各テストケースの入力は，それぞれ以下の形式で与えられる：
```md
$K \enspace T$  
$d_1 \enspace d_2 \enspace \ldots \enspace d_{K-1}$  
$v_1 \enspace v_2 \enspace \ldots \enspace v_{K-1}$

```

出力
-----
答えを出力せよ．  

サンプル
=====
```入力例1
1
5 3
7 9 5 4
3 1 2 3

```
```出力例1
2

```
![](https://user-images.githubusercontent.com/64454054/223932555-eb0270cf-b1eb-4d68-af93-fbde7a3ca9a2.png)

$(l, r) \in \{\, (3, 5), (4, 5) \, \}$ のとき，可能です．

たとえば $(l, r) = (3, 5)$ を選んだとします．  
$3 \; \scriptsize \mathrm{[円]}$ を掛けて馬を改造し，$3 \; \scriptsize \mathrm{[m/秒]}$ で走れるようにすると，場 $3$ から場 $5$ までは $5 + 4 = 9 \; \scriptsize \mathrm {[m]}$ ありますから，$3 \; \scriptsize \mathrm{[秒]}$ 以内(ちょうど)に到達することが可能です．  
また，場 $3$ から 場 $5$ までを時間内に移動できた場合，報酬として $2 + 3 = 5 \; \scriptsize \mathrm{[円]}$ を得ることができるので，これから改造に用いた $3 \; \scriptsize \mathrm{[円]}$ を引いても，利益として $2 \; \scriptsize \mathrm{[円]}$ が残ります．  
したがって $(l, r) = (3, 5)$ は満たします．

たとえば $(l, r) = (1, 4)$ や $(l, r) = (2, 5)$ の場合，どのように馬を改造しても正の利益を得ることはできません．
(報酬を得るためには，$T \; \scriptsize \mathrm{[秒]}$ 以内に移動を完了する必要があることに注意してください．)
