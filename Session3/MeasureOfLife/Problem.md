問題文
=====
MojaMoja 君は，左から順に 0, 1, 2, ... N と番号の付けられた N+1 個のマス目が横一列に連続した盤面を用いてゲームをしています．  
以降これらのマス目を人生と呼びます．  

MojaMoja 君は現在，人生におけるマス 0 にいて，幸福度は 0 です．  
MojaMoja 君がマス i [0 <= i < N] にいるとき，マス i+1 へ移動することができ，移動後のマスでは「よいこと」か「よくないこと」かのいずれかが起こります．マス N にいるときは移動できません．  
マス i [0 < i <= N] で「よいこと」が起こると幸福度が A_i だけ増加し，「よくないこと」が起こると B_i だけ減少します．  
また，「よいこと」は 2 マス以上で連続しませんが，「よくないこと」は最大で K - 1 マスまで連続することがあり得ます(つまり K マス以上では連続しません)．  

ここで，ある人生において，「よいこと」と「よくないこと」の起こり方を順に並べたものを，その人生のルートと呼びます．  
MojaMoja 君が移動できなくなった時点での幸福度を，そのルートのスコアとします．  

人生においてあり得るルートすべてのスコアの総和をその人生の期待度とするとき，(期待度) mod 998244353 を求めてください．  

剰余の性質より，答えは必ず非負整数として表せますが，期待度自体は負の数にもなり得ることに注意してください．  

制約
-----
- 1 <= N, K <= 10^3
- 0 <= A_i, B_i <= 10^9

入力
-----
入力は以下の形式で標準入力から与えられる．
```md
N:5, K:3
A: 3 4 5 7 5
B: 2 3 1 4 2
```

出力
-----
12
答えを出力せよ．  

サンプル
=====
```入力例1

```
```出力例1

```