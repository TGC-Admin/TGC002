# 概要
少し数学的に考えると，操作の性質に気づくことができます．

問題原案：uni_kakurenbo

# 解説

まず， $S$ と $T$ とに含まれている文字とそれらの個数が一致していない場合，明らかに `No` です．

以下では $S$ と $T$ とが含む文字と個数は一致しているものとします．

#### $N \geq 4$ のとき
`Yes` です．  
これは次のように証明できます：
1. $N = 4$ で成り立つことを証明します．  
使われるアルファベットの種類は関係なく，また，同じ文字の重複がない場合に $4! = 24$ 通りすべてを作ることができるならば，重複があっても可能なので，$S =$ `abcd` として，$24$ 通りの並び方がすべて作れるかを調べればよいです．  
BFS などを用いて全探索することで分かります．

1. $N = 4$ で成り立つとき，$N \geq 5$ で成り立つことを示します．  
$S$ の先頭 $i$ 文字までが $T$ に一致していると仮定します．  
$S$ の $i+2$ 文字目以降から適切な文字を移動させてくることで，$S$ の $i+1$ 文字目を $T$ のそれに一致させたいです．  
次のように可能です：
    - 目的の文字が $j \geq i+3$ 文字目にあるとき：  
        - $i+1$ 文字目と $j$ 文字目とを交換する．
    - 目的の文字が $i+2$ 文字目にあるとき：
        - $i+2$ 文字目と $i+4$ 文字目とを交換する．
        - $i+1$ 文字目と $i+4$ 文字目とを交換する．
        
    つまり，少なくとも $4$ 文字分の余裕があれば，既にそろっている部分 ($i$ 文字目まで) に影響を与えずに，$i+1$ 文字目までを $T$ に一致させることができます．

    以上より，$N \geq 5$ のとき，$N-4$ 文字目までは貧欲に前から $T$ に一致させることが可能です．  
    残った $4$ 文字についても，仮定より揃えられます．

#### $N < 4$ のとき
BFS などを用いて，ありうる操作の行い方をすべて試せばよいです．

# 実装例
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

signed main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    if(multiset(s.begin(), s.end()) != multiset(t.begin(), t.end())) {
        cout << "No\n";
        return 0;
    }

    if(n >= 4) {
        cout << "Yes\n";
        return 0;
    }

    queue<string> que;
    unordered_set<string> seen;

    que.push(s), seen.insert(s);

    while(not que.empty()) {
        auto v = que.front(); que.pop();
        if(v == t) {
            cout << "Yes\n";
            return 0;
        }
        REP(i, n) REPF(j, i+2, n) {
            swap(v[i], v[j]);
            if(seen.count(v)) continue;
            seen.insert(v);
            que.push(v);
            swap(v[i], v[j]);
        }
    }

    cout << "No\n" << "\n";

    return 0;
}
```
