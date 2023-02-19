# 概要
愚直な方法では正解できません．  
求めるべきことを明らかにして考えてみましょう．

問題原案：kusirakusira

# 解説
操作後の $A$ の要素は非常に大きくなりうるため，実際に操作を再現して答えを求めることは難しいです．  
別なアプローチを考えてみましょう．  

$P_i$ を $i$ 番目に小さい素数として，整数 $X = P_1^{k_1} \cdot P_2^{k_2} \cdot P_3^{k_3} \cdots$ の総和は $(k_1 + 1) (k_2 + 1) (k_3 + 1) \cdots$ と表されます．  
$X$ のもつ $i$ 番目の素因数を $0$ 個以上 $k_i$ 個以下選ぶ組み合わせの総数です．

$A_i$ の値を，ベクトル $K^{(i)} = (k_1, k_2, k_3, \ldots)$ として持つことを考えます．  

すると，$Q$ 回の操作は各々次のように言い換えることができます：
- $x \eqqcolon P_1^{c_1} \cdot P_2^{c_2} \cdot P_3^{c_3} \cdots$ とする．
- $l \leq i \leq r$ を満たす任意の整数 $i$ について：
    - $K^{(i)}$ を $K^{(i)} + (c_1, c_2, c_3, \ldots)$ で置換する．

以上の操作は素因数ごとに独立ですから，imos法を用いるなどして簡単に実装できます．  
$A_i, x \leq 100$ より，各ベクトルの要素数は高々 $25$ といえます．これは $100$ 以下の素数の個数です．  

求めるべきは，$\displaystyle D_i = \prod_{j} (K^{(i)}_j + 1)$ 
です．

# 実装例
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
using ll = long long;

constexpr int PRIMES[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

// 素因数分解
valarray<int> factorize(int x) {
    valarray<int> res(size(PRIMES));
    REP(i, res.size()) {
        int p = PRIMES[i];
        while(x%p == 0) ++res[i], x /= p;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector powers(n+1, valarray<int>(size(PRIMES)));

    vector<int> a(n); REP(i, n) cin >> a[i];

    REP(i, n) {
        auto factors = factorize(a[i]);
        powers[i] += factors, powers[i+1] -= factors;  // imos法 (差分加算)
    }

    int q; cin >> q;
    REP(_, q) {
        int l, r, x; cin >> l >> r >> x; --l;
        auto factors = factorize(x);
        powers[l] += factors, powers[r] -= factors;  // imos法 (差分加算)
    }

    REP(i, n) powers[i+1] += powers[i];  // imos法 (累積)

    transform(
        powers.begin(), powers.end(),
        ostream_iterator<ll>(cout, " "),
        [](auto& k) -> ll {
            return std::transform_reduce(begin(k), end(k), 1LL, multiplies<ll>{}, [](int e) -> ll { return e + 1; } );
        }
    );
    cout.seekp(-1) << "\n";
}

signed main() {
    int $; cin >> $;
    while($--) solve();
    return 0;
}

```
