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
assert Phi == 1

n = int(input())
assert 1 < n <= 50

for _ in [0] * n:
    s, t, u = map(int, input().split())
    assert 0 <= s < t < u < 1 << 30
