#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)

signed main() {
    {
    int h, w; cin >> h >> w;
    vector<int> grid(h*w, 0);

    auto id = [&w](int i, int j) { return i*w + j; };

    REP(i, h) REP(j, w) {
        char c; cin >> c;
        grid[id(i,j)] = c == '#';
    }

    vector<vector<pair<int,int>>> graph(h*w);

    REP(i, h) REP(j, w) {
        constexpr pair<int,int> DIRS[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        for(auto &[di, dj] : DIRS) {
            int ni = i + di, nj = j + dj;
            if(ni < 0 or ni >= h or nj < 0 or nj >= w) continue;
            graph[id(i,j)].emplace_back(id(ni,nj), grid[id(ni,nj)]);
        }
    }

    int dist = 0;
    {
        deque<int> que;
        vector<int> dists(graph.size(), INT32_MAX);

        que.push_back(0), dists[0] = 0;

        while(not que.empty()) {
            int v = que.front(); que.pop_front();
            for(auto [nv, cost] : graph[v]) {
                int dist = dists[v] + cost;
                if(dist < dists[nv]) {
                    dists[nv] = dist;
                    if(cost) que.push_back(nv);
                    else que.push_front(nv);
                }
            }
        }
        dist = *dists.rbegin();
    }

    int n; cin >> n;
    vector<int> c(n); REP(i, n) cin >> c[i];

    int ans = 0;
    {
        int acc = 0;
        REP(i, min(n, reduce(grid.begin(), grid.end()))) {
            acc += c[i];
            if(dist <= i) ans = min(ans, acc);
        }
    }

    cout << ans << "\n";
}
