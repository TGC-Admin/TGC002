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

N = 0
for phi in range(Phi):
    n, k = map(int, input().split())
    D = [*map(int, input().split())]
    assert 1 <= n
    assert 1 <= k <= 10 ** 12
    assert D[0] == 0
    assert all(0 < a < n for a in D[1:])
    N += n
assert N <= 10 ** 5
