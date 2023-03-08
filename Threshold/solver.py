for _ in range(int(input())):
    n, k = map(int, input().split())
    A = sorted(map(int, input().split()))

    r, ans = 0, 0
    for l in range(n):
        while r != n and A[r] - A[l] <= 2*k:
            r += 1
        ans = max(ans, r - l)

    print(ans)
