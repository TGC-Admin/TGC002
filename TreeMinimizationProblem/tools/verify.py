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

N, Q = 0, 0
for phi in range(Phi):
    debug(phi)
    n = int(input())
    assert 1 < n <= 10 ** 4
    for i in range(2, n+1):
        p, w = map(int, input().split())
        assert 1 <= p < i
        assert abs(w) <= 10 ** 6
    q = int(input())
    assert 1 <= q
    for i in range(q):
        a, b = map(int, input().split())
        assert 1 <= a < b <= n
    N += n
    Q += q

assert N <= 10 ** 5
assert Q <= 10 ** 5
