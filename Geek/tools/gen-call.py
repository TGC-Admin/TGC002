import os
from random import randint
import sys
import joblib

args = sys.argv

id = str(int(args[1])).zfill(4)
Phi = int(args[2])
Q = int(args[3])

file = open(f"testcases/in/01_test-{id}.txt", "w")
file.write(str(Phi) + "\n")

def call():
    if Q > 0: q = Q
    if Q == 0: q = 10 ** 5 // Phi
    if Q == -1: q = randint(1, 10 ** 5 // Phi)
    file.write(os.popen(f"./tools/gen-impl.exe { randint(0, 1 << 30) } { q }").read())

joblib.Parallel(n_jobs=1)(
    joblib.delayed(call)() for _ in [0] * Phi
)

file.close()
