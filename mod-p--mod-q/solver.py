from math import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

for _ in range(int(input())):
    p, q, k = map(int, input().split())
    m, l = max(p, q), lcm(p, q)
    print((k // l) * m + min(m, k % l))
