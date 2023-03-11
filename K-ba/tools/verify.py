# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

Phi = int(input())
assert 1 <= Phi <= 10 ** 5

K = 0
for phi in range(Phi):
    debug(phi)
    k, t = map(int, input().split())
    assert 2 <= k
    assert 1 <= t < 1 << 30

    D = [*map(int, input().split())]
    assert all(0 <= d for d in D)
    assert sum(D) < 1 << 30
    assert len(D) == k-1

    V = [*map(int, input().split())]
    assert all(0 <= v for v in V)
    assert sum(V) < 1 << 30
    assert len(V) == k-1
    K += k

assert K <= 10 ** 6
