#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;

#define REP(i,n) for(i32 i=0, i##_length=i32(n); i<i##_length; ++i)


signed main() {
    i32 h, w; std::cin >> h >> w;
    std::vector<i32> grid(h*w, 0);

    const auto id = [w](const i32 i, const i32 j) { return i*w + j; };

    REP(i, h) REP(j, w) {
        char c; std::cin >> c;
        grid[id(i,j)] = c == '#';
    }

    std::vector<std::vector<std::pair<i32,i32>>> graph(h*w);

    REP(i, h) REP(j, w) {
        constexpr std::pair<i32,i32> DIRS[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        for(const auto &[di, dj] : DIRS) {
            i32 ni = i + di, nj = j + dj;
            if(ni < 0 or ni >= h or nj < 0 or nj >= w) continue;
            graph[id(i,j)].emplace_back(id(ni,nj), grid[id(ni,nj)]);
        }
    }

    i32 dist = 0;
    {
        std::deque<i32> que;
        std::vector<i32> dists(graph.size(), INT32_MAX);

        que.push_back(0), dists[0] = 0;

        while(not que.empty()) {
            i32 v = que.front(); que.pop_front();
            for(auto [nv, cost] : graph[v]) {
                i32 dist = dists[v] + cost;
                if(dist < dists[nv]) {
                    dists[nv] = dist;
                    if(cost) que.push_back(nv);
                    else que.push_front(nv);
                }
            }
        }
        dist = *dists.rbegin();
    }

    i32 n; std::cin >> n;
    std::vector<i32> c(n); REP(i, n) std::cin >> c[i];

    i32 ans = 0;
    {
        i32 acc = 0;
        REP(i, std::min(n, std::reduce(grid.begin(), grid.end()))) {
            acc += c[i];
            if(dist <= i) ans = std::min(ans, acc);
        }
    }

    std::cout << ans << "\n";
}
