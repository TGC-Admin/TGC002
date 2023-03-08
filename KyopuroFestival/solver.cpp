#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

#include <atcoder/mincostflow>

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


std::pair<i32,i64> solver(
    const i32 n,
    const std::vector<i32> s,
    const std::vector<i32> t,
    const std::vector<i32> u
) {

    atcoder::mcf_graph<i32,i64> G(2*n+2);

    REP(i, n) REP(j, n) {
        if(s[j] <= u[i] and u[i] <= t[j]) {
            G.add_edge(i, n+j, 1, t[j] - u[i]);
        }
    }

    REP(i, n) {
        G.add_edge(2*n, i, 1, 0);
        G.add_edge(n+i, 2*n+1, 1, 0);
    }

    const auto [ flow, cost ] = G.flow(2*n, 2*n+1);
    return { n - flow, cost };
}

signed main() {
    i32 $; std::cin >> $;
    while($--) {
        i32 n; std::cin >> n;
        std::vector<i32> s(n), t(n), u(n);
        REP(i, n) std::cin >> s[i] >> t[i] >> u[i];

        const auto ans = solver(n, s, t, u);
        std::cout << ans.first << " ";
        std::cout << ans.second << "\n";
    }
}
