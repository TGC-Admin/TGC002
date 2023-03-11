import os
from random import randint
import sys
import joblib

args = sys.argv

id = str(int(args[1])).zfill(4)
Phi = int(args[2])
K = int(args[3])

file = open(f"testcases/in/01_test-{id}.txt", "w")
file.write(str(Phi) + "\n")

def call():
    if K > 0: k = K
    if K == 0: k = 10 ** 5 // Phi
    if K == -1: k = randint(2, 10 ** 5 // Phi)
    if K == -2: k = 10 ** 6 // Phi
    file.write(os.popen(f"./tools/gen-impl.exe { randint(0, 1 << 30) } { k }").read())

joblib.Parallel(n_jobs=1)(
    joblib.delayed(call)() for _ in [0] * Phi
)

file.close()
