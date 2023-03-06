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
assert 1 <= Phi <= 10 ** 3

N, K = 0, 0
for phi in range(Phi):
    n, k = map(int, input().split())
    assert 1 <= n
    assert 1 <= k
    A = [*map(int, input().split())]
    B = [*map(int, input().split())]
    assert all(0 <= a < 1 << 30 for a in A)
    assert all(0 <= b < 1 << 30 for b in B)
    N += n
    K += k

assert N <= 10 ** 3 and K <= 10 ** 3
