**この問題はサンプルです**  

# 注意
[**Sample 0**](https://mojacoder.app/users/uni_kakurenbo/problems/TG-BsAC-002_S0.000) の注意事項を先にお読みください。

問題文
=====
頂点に $0$ から $10^5 - 1$ までの番号のついた $10^5$ 頂点 $0$ 辺のグラフがあります．

$Q$ 個のクエリを処理してください．  
$k$ 番目のクエリは以下です：
- $t_k = 0$ のとき：
    - 頂点 $x_k$ を含む連結成分に属する全ての頂点と，頂点 $y_k$ を含む連結成分に属する全ての頂点との間に無向辺を張る．  
- $t_k = 1$ のとき：
    - $x_k \leq i < y_k$ をみたす全ての $i$ について，頂点 $i$ を端点としてもつ全ての辺を削除する．
- $t_k = 2$ のとき：
    - 頂点 $x_k$ と頂点 $y_k$ とが同じ連結成分に属するか調べる．
    - 属するなら `Yes`，そうでないなら `No` と出力する．

制約
-----
- $1 \leq \Phi \leq 10^5$
- $1 \leq Q$
- $\sum_{\phi} \Phi_{\phi}(Q) \leq 10^5$
- $t_k \in \{\, 0, 1, 2 \,\} \; \scriptsize (1 \leq k \leq Q)$
- $0 \leq x_k < y_k < 10^5 \; \scriptsize (1 \leq k \leq Q)$

入力
-----
各テストケースの入力は，それぞれ以下の形式で与えられる：
```md
$Q$  
$t_1 \enspace x_1 \enspace y_1$  
$t_2 \enspace x_2 \enspace y_2$  
$\vdots$  
$t_Q \enspace x_Q \enspace y_Q$  

```

出力
-----
問題文中のクエリにしたがって，適する内容を出力せよ．

サンプル
===
```入力例1
1
5
2 0 1
0 0 1
2 0 1
1 0 1
2 0 1

```
```出力例1
No
Yes
No

```

---
```入力例2
3
2
0 0 1
2 0 1
1
0 0 1
12
0 0 5
0 1 2
0 2 5
0 5 10
2 0 10
2 1 10
1 1 5
2 0 10
2 1 10
0 1 100
2 0 100
2 1 100

```
```出力例2
Yes
Yes
Yes
Yes
No
No
Yes

```
$2$ つ目のテストケースでは出力がないことに注意してください．

---
- [Sample 0](https://mojacoder.app/users/uni_kakurenbo/problems/TG-BsAC-002_S0.000)
- [Sample 1](https://mojacoder.app/users/uni_kakurenbo/problems/TG-BsAC-002_S1.000)
