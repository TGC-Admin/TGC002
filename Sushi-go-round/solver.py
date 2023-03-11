for _ in [0] * int(input()):
    n = int(input())
    A = map(int, input().split())
    rev = [0] * n
    for i, a in enumerate(A): rev[a] = i
    ans = 0
    for i in range(n-1):
        ans += rev[i+1] < rev[i]
    print(ans)
