from math import lcm

for _ in range(int(input())):
    p, q, k = map(int, input().split())
    print((k // lcm(p, q)) * max(p, q) + min(max(p, q), k % lcm(p, q)))
