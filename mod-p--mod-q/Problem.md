問題文
=====
$T$ 個のテストデータが与えられます．  
$t \scriptsize \hspace{0.3em} (1 \leq t \leq T)$ 個目のテストデータでは，$(P, Q, K) \coloneqq (P_t, Q_t, K_t)$ として次の問題を解いてください：

- $P, Q$ は正の整数である．
- $K$ 未満の非負整数 $x$ であって，次の**条件**を満たすものはいくつあるか？
- **条件**：
    -  $(x \bmod P) \bmod Q = (x \bmod Q) \bmod P$ 
- 求めよ．

制約
-----
- $1 \leq T \leq 10^4$
- $1 \leq P_t, Q_t \leq 10^9 \; \scriptsize (1 \leq t \leq T)$
- $1 \leq K_t \leq 10^{18} \; \scriptsize (1 \leq t \leq T)$

入力
-----
入力は以下の形式で標準入力から与えられる．
```md
$T$  
$P_1 \enspace Q_1 \enspace K_1$  
$P_2 \enspace Q_2 \enspace K_2$  
$\vdots$  
$P_T \enspace Q_T \enspace K_T$  
```

出力
-----
$T$ 行出力せよ．  
$t \scriptsize \hspace{0.3em} (1 \leq t \leq T)$ 行目には $t$ 個目のテストデータに対する答えを出力せよ． 

サンプル
=====
```入力例1

```
```出力例1

```
