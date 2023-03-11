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

N = 0
for phi in range(Phi):
    debug(phi)
    n = int(input())
    assert 1 <= n
    A = [*map(int, input().split())]
    assert all(abs(a) < 1 << 30 for a in A)
    assert len(A) == n
    N += n

assert N <= 10 ** 5
