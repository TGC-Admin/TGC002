# 概要
条件を整理して扱いやすい形にしましょう．

問題原案：uni_kakurenbo

# 解説

$d$ や $v$ の添え字を 0-based indexing とします．

利益を正とできるような $(l, r)$ の条件を考えます．  

$d, v$ それぞれの累積和 $D, V$ を次のように定めます：
- $D_0 = V_0 = 0$
- $\displaystyle D_k = \sum_{ 0 \leq i < k } d_k$
- $\displaystyle V_k = \sum_{ 0 \leq i < k } v_k$

すると，$2$ 場 $l, r$ 間について，
- 道のり： $D_r - D_l \; \scriptsize \mathrm{[m]}$
- クリア時の報酬： $V_r - V_l \; \scriptsize \mathrm{[円]}$

と表すことができます．

利益を「正」とするためには報酬 $V_r - V_l \; \scriptsize \mathrm{[円]}$ **以上**の金額を改造に費やしてならないので，最大で $V_r - V_l - 1 \; \scriptsize \mathrm{[円]}$ まで使うことができます．  
この問題を解くうえでは，必ず使える最大の金額を費やして改造することとして問題ありません．

$V_r - V_l - 1 \; \scriptsize \mathrm{[円]}$ を費やして改造された馬が，$T \; \scriptsize \mathrm{[秒]}$ で走りきることのできる距離の最大値は $T (V_r - V_l - 1) \; \scriptsize \mathrm{[m]}$ ですから，正の利益が期待できる組 $(l, r)$ は結局以下をみたすとわかります：
- $D_r - D_l \leq T (V_r - V_l - 1) \;\; \scriptsize (l < r)$

これを満たす $l, r$ を数えたいです．  
$l, r$ が散らばっていると扱いづらいので，この条件を変形して都合よく整理します．  
$D_r - D_l \leq T (V_r - V_l - 1) \Leftrightarrow (T V_l - D_l) \leq (T V_r - D_r) - T$ ですから，$S_k = T V_k - D_k$ とすると，最終的に条件は以下のように書けると分かります：
- $S_l \leq S_r - T  \; \scriptsize (l < r)$ 

これを満たす $(l, r)$ の組は，一点加算および区間和取得のできるデータ構造を用いることで数え上げられます．(転倒数を高速に求める方法に似ていると思います．)  

ただし，$S$ の要素のとりうる範囲が広いため，Binary Indexed Tree などにそのまま乗せることは難しいです．  

大小関係のみが分かればよいことに注目すると，$S$ および $S - T$ の値をまとめて座標圧縮し，その圧縮後の値を用いて計算を行えばよいと分かります．

$O(K \log K)$ 時間などで解くことができます．

なお，制約がタイトであるため，計算量のオーダーが同程度のアルゴリズムでも定数倍によって判定が分かれる場合があります．


解説：uni_kakurenbo

# 実装例
```cpp:C++
#include <cstdint>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>

#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/combine.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/join.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>

#include <atcoder/fenwicktree>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


i64 solve(const i32 k, const i64 t, const std::vector<i64>& d, const std::vector<i64>& v) {
    std::vector<i64> p = { 0 }, q = { 0 };  // 累積和
    std::inclusive_scan(d.begin(), d.end(), std::back_inserter(q));
    std::inclusive_scan(v.begin(), v.end(), std::back_inserter(p));

    std::vector<i64> s;
    boost::transform(
        boost::combine(p, q), std::back_inserter(s),
        [t](const auto& e) { return t * boost::get<0>(e) - boost::get<1>(e); }
    );

    // 座標圧縮
    std::vector<i64> s_v;
    {
        boost::copy(
            boost::join(s, s | boost::adaptors::transformed([t](const i64 e) { return e - t; })),
            std::back_inserter(s_v)
        );
        boost::sort(s_v);
        s_v.erase(std::unique(s_v.begin(), s_v.end()), s_v.end());
    }

    const auto s_rank = [&s_v](const i64 v) {
        return std::distance(s_v.begin(), boost::lower_bound(s_v, v));
    };

    atcoder::fenwick_tree<i32> cnt(k*2);

    return (
        boost::accumulate(
            s, 0LL,
            [&](const i64 acc, const i64 e) -> i64 {
                cnt.add(s_rank(e), 1);
                return acc + cnt.sum(0, s_rank(e - t) + 1);  // T > 0 より自分自身がカウントされることはない
            }
        )
    );
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 k, t; std::cin >> k >> t;
        std::vector<i64> d(k-1), v(k-1);
        REP(i, k-1) std::cin >> d[i];
        REP(i, k-1) std::cin >> v[i];
        std::cout << solve(k, t, d, v) << "\n";
    }
}

```
