#include "template.hpp"
#include "grid.hpp"
#include "graph.hpp"
#include "graph/topological_sort.hpp"

signed main() {
    int h, w; std::cin >> h >> w;
    lib::grid<char> grid(h, w); grid.read();
    debug(grid);
    lib::graph G(h*w);
    REP(i, h) REP(j, w) {
        int di = 0, dj = 0;
        if(grid(i,j) == 'D') di = 1;
        if(grid(i,j) == 'U') di = -1;
        if(grid(i,j) == 'R') dj = 1;
        if(grid(i,j) == 'L') dj = -1;
        int vi = i, vj = j;
        while(true) {
            vi += di, vj += dj;
            if(vi < 0 or vi >= h or vj < 0 or vj >= w) break;
            G.add_edge(vi*w+vj, i*w+j);
        }
    }
    std::vector<int> sorted;
    G.sort_topologically(&sorted);
    debug(sorted);
    print(sorted.size());
}
