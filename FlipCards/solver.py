from functools import reduce

def add(a, b):
    return (a + b) % MOD

MOD = 998244353

for _ in [0] * int(input()):
    n, k = map(int, input().split())
    A = [*map(int, input().split())]
    B = [*map(int, input().split())]

    dp0 = [[0] * (k+1) for _ in [0] * (n+1)]
    dp1 = [[0] * (k+1) for _ in [0] * (n+1)]

    dp0[0][0] = dp0[0][1] = 1

    for i in range(n):
        dp0[i+1][0] = reduce(add, dp0[i][1:])
        dp1[i+1][0] = reduce(add, dp1[i][1:]) + dp0[i][0] * A[i] % MOD
        for j in range(1, k+1):
            dp0[i+1][j] = dp0[i][j-1]
            dp1[i+1][j] = dp1[i][j-1] + dp0[i][j] * B[i] % MOD

    print(reduce(add, dp1[n]))
