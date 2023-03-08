#Thnaks to: https://tjkendev.github.io/procon-library/python/graph/lca-segment-tree.html
class LowerCommonAncestor(object):
    class TreeNode(object):
        def __init__(self, x):
            self.val = x
            self.left = None
            self.right = None

    def __init__(self, G):
        self.N = len(G)
        self.S = []
        self.F = [0] * self.N
        depth = [0] * self.N
        def dfs(v, d):
            self.F[v] = len(self.S)
            depth[v] = d
            self.S.append(v)
            for nv, _w in G[v]:
                dfs(nv, d+1)
                self.S.append(v)
        dfs(0, 0)

        self.INF = (self.N, None)

        M = 2 * self.N
        self.M0 = 2 ** (M-1).bit_length()
        self.data = [self.INF] * (2 * self.M0)
        for i, v in enumerate(self.S):
            self.data[self.M0-1+i] = (depth[v], i)
        for i in range(self.M0-2, -1, -1):
            self.data[i] = min(self.data[2*i+1], self.data[2*i+2])

    def _query(self, a, b):
        yield self.INF
        a += self.M0; b += self.M0
        while a < b:
            if b & 1:
                b -= 1
                yield self.data[b-1]
            if a & 1:
                yield self.data[a-1]
                a += 1
            a >>= 1; b >>= 1

    def query(self, u, v):
        fu = self.F[u]; fv = self.F[v]
        if fu > fv:
            fu, fv = fv, fu
        return self.S[min(self._query(fu, fv+1))[1]]

for _ in range(int(input())):
    n = int(input())

    G = [list(()) for _ in [0] * n]
    for i in range(1, n):
        p, w = map(int, input().split())
        p -= 1
        G[p].append((i, w))

    lca = LowerCommonAncestor(G)

    diff = [0] * n

    q = int(input())
    for _ in [0] * q:
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        diff[a] += 1
        diff[b] += 1
        diff[lca.query(a, b)] -= 2

    cnt = [0] * n
    def dfs(v):
        acc = 0
        for nv, w in G[v]:
            acc += dfs(nv)
        cnt[v] = acc + diff[v]
        return cnt[v]
    dfs(0)

    sum_cost, max_contrib = 0, -10**100
    for v in range(n):
        for nv, w in G[v]:
            cntrib = cnt[nv] * w
            sum_cost += cntrib
            max_contrib = max(max_contrib, cntrib)

    print(min(sum_cost, sum_cost - max_contrib))
