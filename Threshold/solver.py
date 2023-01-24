from collections import Counter


n, k = map(int, input().split())
A = [*map(int, input().split())]

S = sorted(set(A))
cnt = Counter(A)

l, ans, pro_ans = S[0], 0, 0
for r in S:
    pro_ans += cnt[r]
    while r - l > 2*k:
        pro_ans -= cnt[l]
        l += 1
    ans = max(ans, pro_ans)

print(ans)
