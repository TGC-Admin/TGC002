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

#include <atcoder/segtree.hpp>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)
#define REPF(i,l,r) for(auto i=(l), i##_last=(r); i<i##_last; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }

i32 e() { return 0; }
i32 op(i32 x, i32 y) { return x + y; }

i64 solve(const i32 k, const i64 t, const std::vector<i64>& d, const std::vector<i64>& v) {
    std::vector<i64> p = { 0 }, q = { 0 };
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

    atcoder::segtree<i32,op,e> cnt(k*2);

    return (
        boost::accumulate(
            s, 0LL,
            [&](const i64 acc, const i64 e) -> i64 {
                cnt.set(s_rank(e), cnt.get(s_rank(e)) + 1);
                return acc + cnt.prod(0, s_rank(e - t) + 1);  // T > 0 より自分自身がカウントされることはない
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
