from itertools import accumulate
from sys import stdin

# Thanks to: https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree
class BIT:
    def __init__(self, n):
        self.size = n
        self.data = [0] * (n + 1)

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, p):
        s = 0
        while p > 0:
            s += self.data[p]
            p -= p & -p
        return s

    def add(self, p, x):
        p += 1
        while p <= self.size:
            self.data[p] += x
            p += p & -p


for _ in [0] * int(input()):
    K, T = map(int, input().split())

    D = [0]; D.extend(accumulate(map(int, input().split())))
    V = [0]; V.extend(accumulate(map(int, input().split())))
    # print(V)

    S = [*map(lambda p: T*p[0] - p[1], zip(V, D))]
    # print(S)

    ranks = { x : i for i, x in enumerate(sorted(list(set(S) | set(s - T for s in S)))) }

    bit = BIT(2*K)

    ans = 0
    for i in range(K):
        ans += bit.sum(0, ranks[S[i] - T] + 1)
        bit.add(ranks[S[i]], 1)

    print(ans)
