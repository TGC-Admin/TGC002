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

N_sum = 0
for phi in range(Phi):
    debug(phi)
    N, K = map(int, input().split())
    assert 1 <= N
    assert 0 <= K <= 10 ** 9
    A = [*map(int, input().split())]
    assert all(abs(a) <= 10 ** 9 for a in A)
    assert len(A) == N

assert N_sum <= 10 ** 5
