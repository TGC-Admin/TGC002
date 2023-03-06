import os
from random import randint
import sys
import joblib

args = sys.argv

id = str(int(args[1])).zfill(4)
Phi = int(args[2])
N = int(args[3])
K = int(args[4])

file = open(f"testcases/in/01_test-{id}.txt", "w")
file.write(str(Phi) + "\n")

def call():
    if N > 0: n = N
    if N == 0: n = 10 ** 5 // Phi
    if N == -1: n = randint(1, 10 ** 5 // Phi)
    if K > 0: k = K
    if K == 0: k = randint(0, 10 ** randint(0, 9))
    file.write(os.popen(f"./tools/gen-impl.exe { randint(0, 1 << 30) } { n } { k }").read())

joblib.Parallel(n_jobs=1)(
    joblib.delayed(call)() for _ in [0] * Phi
)

file.close()
