import os
from random import randint
import sys
import joblib

args = sys.argv

id = str(int(args[1])).zfill(4)
Phi = int(args[2])
Q = int(args[3])
Max_xy = int(args[4])
T = int(args[5])

if Q < 0: Q = 10 ** 5 // Phi

file = open(f"testcases/in/01_test-{id}.txt", "w")
file.write(str(Phi) + "\n")

def call():
    cmd = f"./tools/gen-impl.exe { randint(0, 1 << 30) } { Q } { Max_xy } { randint(0, 1) } { T }"
    # print(cmd)
    file.write(os.popen(cmd).read())

joblib.Parallel(n_jobs=1)(
    joblib.delayed(call)() for _ in [0] * Phi
)

file.close()
