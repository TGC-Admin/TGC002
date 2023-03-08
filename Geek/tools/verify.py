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
    k = int(input())
    assert 1 <= k

    for _ in [0] * k:
        t, x = map(int, input().split())
        assert t in (0, 1)
        assert 1 <= x <= 10 ** 9

    K += k

assert K <= 10 ** 5
