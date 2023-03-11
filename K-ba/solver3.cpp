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

#include "template.hpp"

#include "data_structure/implicit_treap.hpp"
#include "data_structure/range_action/range_add_range_sum.hpp"

i64 solve(const i32 k, const i64 t, const std::vector<i64>& d, const std::vector<i64>& v) {
    std::vector<i64> p = { 0 }, q = { 0 };
    std::inclusive_scan(d.begin(), d.end(), std::back_inserter(q));
    std::inclusive_scan(v.begin(), v.end(), std::back_inserter(p));

    std::vector<i64> s;
    boost::transform(
        boost::combine(p, q), std::back_inserter(s),
        [t](const auto& e) { return t * boost::get<0>(e) - boost::get<1>(e); }
    );

    lib::implicit_treap<lib::actions::range_add_range_sum<i32>> cnt;

    return (
        boost::accumulate(
            s, 0LL,
            [&](const i64 acc, const i64 e) -> i64 {
                cnt.apply(e, 1);
                return acc + cnt.prod(0, e - t + 1);  // T > 0 より自分自身がカウントされることはない
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
