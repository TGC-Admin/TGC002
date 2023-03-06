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

for phi in range(Phi):
    P, Q, K = map(int, input().split())
    assert 1 <= P < 1 << 30
    assert 1 <= Q < 1 << 30
    assert 0 <= K < 1 << 60
