for _ in [0] * int(input()):
    n = int(input()) + 1
    ans = 0
    p = 2
    while p <= n:
        ans += n // p
        p *= 2
    print(ans)
