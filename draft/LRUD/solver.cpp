#include "template.hpp"
#include "grid.hpp"
#include "graph.hpp"
#include "graph/topological_sort.hpp"

using i32 = std::int32_t;
using i64 = std::int64_t;


signed main() {
    i32 h, w; std::cin >> h >> w;
    lib::grid<char> grid(h, w); grid.read();
    debug(grid);
    lib::graph G(h*w);
    REP(i, h) REP(j, w) {
        i32 di = 0, dj = 0;
        if(grid(i,j) == 'D') di = 1;
        if(grid(i,j) == 'U') di = -1;
        if(grid(i,j) == 'R') dj = 1;
        if(grid(i,j) == 'L') dj = -1;
        i32 vi = i, vj = j;
        while(true) {
            vi += di, vj += dj;
            if(vi < 0 or vi >= h or vj < 0 or vj >= w) break;
            G.add_edge(vi*w+vj, i*w+j);
        }
    }
    std::vector<i32> sorted;
    G.sort_topologically(&sorted);
    debug(sorted);
    print(sorted.size());
}
