from random import shuffle


N = 10 ** 5
K = 4999900001

print(1)
print(N, K)

D = [0] * (N-1)
for i in range(N-1):
    D[i] = i%2 + 1

shuffle(D)

print(0, *D)
