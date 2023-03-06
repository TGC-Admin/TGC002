def solve(n, s, t):
    if s == t:
        return True
    if sorted(s) != sorted(t):
        return False
    if n <= 2:
        return False
    if n == 3:
        return s[1] == t[1]
    return True

for _ in [0] * int(input()):
    n = int(input())
    s = input()
    t = input()
    print("Yes" if solve(n, s, t) else "No")
