from math import lcm
p, q, k = map(int, input().split())

print((k // lcm(p, q)) * q + min(q, k % lcm(p, q)))
