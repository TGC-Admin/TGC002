問題文
=====
ある祭りでは，$N$ 個のプログラミングコンテストが開催されます．  
何人かでチームを組んで，これらすべてのコンテストを楽しく網羅したいです．  

$i$ 個目のコンテストは，時刻 $s_i$ から時刻 $t_i$ まで参加登録が可能で，時刻 $t_i$ から競技が始まり，時刻 $u_i$ に終了します．$\scriptsize(1 \leq i \leq N)$  

任意の競プロerは，次のようにして活動を開始することができます：  
- $1 \leq i \leq N$ なる整数 $i$ を選び，時刻 $t_i$ に $i$ 番目のコンテストに参加する．

また，任意の競プロerは競プロ中毒であって，活動を開始した後は常にいずれかのコンテストに参加していたいと思っています．

したがって，自身が以前に参加したコンテストが時刻終了するたびに，以下のうちいずれかを行います：
- コンテストの終了時刻を $u$ として，$1 \leq i \leq N$ かつ $s_i \leq u \leq t_i$ を満たす整数 $i$ を選び，$i$ 番目のコンテストへの参加登録を行う．  
- 爆発する．  

なお，一度参加登録をしたコンテストについては，そのコンテストの競技が終了するまで他の行動はできません．  
また，一度爆発した競プロerは，以降いかなる活動をも行うことはできません．  


任意の競プロerは十分に強いので，参加したコンテストすべてにおいて賞金を得ることができます．  
また，**待ち時間**が長いとそわそわしてしまいます．


さて，次の条件を満たすようにチームを一つ構成します：
- 同一の競プロerが，同時に複数のコンテストに参加することがない．
- 同一のチームに属する複数人の競プロerが，重複して同一のコンテストに参加することがない．
- チームとして，$N$ 個すべてのコンテストで賞金を得ることができる．
- そのような構成のうち，以下のように定められる待ち時間 $W$ が最小である．
    - チームが $n$ 人によって構成されるとする．
    - $\displaystyle W := \sum_{1 \leq k \leq n} w_k$ を満たす．
    - $w_k$ は以下のように定められる：
        - $k$ 人目のチームメンバーは，$c_1, c_2, \ldots, c_{m_k}$ の $m_k$ 個のコンテストに参加するとする．
        - $\large\displaystyle w_k = \sum_{1 \leq i < m_k} (t_{c_{i+1}} - u_{c_i})$ を満たす．
        - なお $m_k = 0$ や $m_k = 1$ のとき，$w_k = 0$ であることに留意せよ．

最小のチームの構成人数 $n$ と，そのようなチームでの最小の待ち時間 $W$ とを求めてください．

制約
-----
- $1 \leq N \leq 50$
- $0 \leq s_i < t_i < u_i \leq 10^9 \scriptsize \; (1 \leq i \leq N)$

入力
-----
入力は以下の形式で標準入力から与えられる．
```md
$N$  
$s_1 \enspace t_1 \enspace u_1$  
$s_2 \enspace t_2 \enspace u_2$  
$\vdots$  
$s_N \enspace t_N \enspace u_N$  
```

出力
-----
答えを出力せよ．  

サンプル
=====
```入力例1
5
0 2 4
0 1 9
3 6 14
13 22 25
7 18 24
```
```出力例1
2 19
```
![](https://u.cubeupload.com/kakurenbo/3desample0001.png)

たとえば，$1$ 人の競プロerが $1, 3, 4$ 個目のコンテストに参加し，もう $1$ 人の競プロerが $2, 5$ 番目のコンテストに参加することで，すべてのコンテストを網羅することができます．  
また，$2$ 人未満の競プロerでこれを達成することはできません．  
これを達成する方法はこの $1$ 通りしかありません．  
このときの待ち時間の総和は $\{ (6 - 4) + (22 - 14) \} + \{ (18 - 9) \} = (2 + 8) + 9 = 19$ です．

```入力例2
3
1 2 3
2 3 4
4 5 6
```
```出力例2
2 1
```

$1$ 個目のコンテストに参加した競プロerは，そのコンテストが終了した直後にいずれのコンテストにも参加することができません．したがって爆発します．  
残った $2$ つのコンテストで賞金を得るためにはもう $1$ 人の競プロerが必要です．  