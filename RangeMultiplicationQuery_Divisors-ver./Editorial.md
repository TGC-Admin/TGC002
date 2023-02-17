# 概要
愚直な方法では正解できません．  
求めるべきことを明らかにして考えてみましょう．

問題原案：kusirakusira

# 解説
操作後の $A$ の要素は非常に大きくなりうるため，実際に操作を再現して答えを求めることは難しいです．  
別なアプローチを考えてみましょう．  

$P_i$ を $i$ 番目に小さい素数として，整数 $X = P_1^{k_0} \cdot P_2^{k_0} \cdot P_3^{k_0} \cdots$ の総和は $(k_1 + 1) (k_2 + 1) (k_3 + 1) \cdots$ と表されます．  
$X$ のもつ $i$ 番目の素因数を $0$ 個以上 $k_i$ 個以下選ぶ組み合わせの総数です．

$A_i$ の値を，ベクトル $K^{(i)} = (k_1, k_2, \ldots)$ として持つことを考えます．  
$A_i, x \leq 100$ より，各ベクトルの要素数は高々 $25$ といえます．これは $100$ 以下の素数の個数です．  

$Q$ 回の操作は次のように言い換えることができます：
- $x \coloneqq P_1^{c_1} \cdot P_2^{c_2} \cdots P_{25}^{c_{25}}$ とする．
- $l \leq i \leq r$ を満たす任意の整数 $i$ について：
    - $1 \leq j \leq 25$ を満たす任意の整数 $p$ について：
        - $\large K^{(i)}_j$ を $\large K^{(i)}_j + P_j^{c_{j}}$ で置換する．

以上の操作は素因数ごとに独立ですから，imos法を用いるなどして簡単に実装できます．  

求めるべきは，$\displaystyle D_i = \prod_{1 \leq j \leq 25} K^{(i)}_j$ 
です．

# 実装例
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
using ll = long long;

constexpr int PRIMES[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
constexpr int P = size(PRIMES);

template<class T> std::map<T,int> factorize(T x) {
    std::map<T,int> res;
    for(T v=2; v*v <= x; ++v) {
        if(x%v != 0) continue;
        while(x%v == 0) ++res[v], x /= v;
    }
    if(x != 1) res[x] = 1;
    return res;
}

void solve() {
    int n; cin >> n;
    vector powers(n+1, valarray<int>(P));

    vector<int> a(n); REP(i, n) cin >> a[i];

    REP(i, n) {
        auto factors = factorize(a[i]);
        REP(j, P) {
            powers[i][j] += factors[PRIMES[j]];
            powers[i+1][j] -= factors[PRIMES[j]];
        }
    }

    int q; cin >> q;
    REP(_, q) {
        int l, r, x; cin >> l >> r >> x; --l;

        auto factors = factorize(x);
        REP(j, P) {
            // imos法 (差分加算)
            powers[l][j] += factors[PRIMES[j]];
            powers[r][j] -= factors[PRIMES[j]];
        }
    }

    // imos法 (累積)
    REP(i, n) powers[i+1] += powers[i];

    REP(i, n) {
        ll ans = 1;
        REP(j, P) ans *= powers[i][j] + 1;
        cout << ans << " ";
    }
    cout << "\n";
}

signed main() {
    int $; cin >> $;
    while($--) solve();
    return 0;
}
```
