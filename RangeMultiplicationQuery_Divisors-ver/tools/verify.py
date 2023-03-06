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
assert 1 <= Phi <= 10 ** 4

N, Q = 0, 0
for phi in range(Phi):
    n, q = map(int, input().split())
    assert 1 <= n and 1 <= q
    for _ in [0] * q:
        l, r, x = map(int, input().split())
        assert 1 <= l <= r <= n
        assert 1 <= x <= 100
    N += n
    Q += q
assert N <= 10 ** 5 and Q <= 10 ** 5
