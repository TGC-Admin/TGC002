import os
from random import randint
import sys
import joblib

args = sys.argv

id = str(int(args[1])).zfill(4)
Phi = int(args[2])
Q = int(args[3])
Max_xy = int(args[4])

if Q < 0: Q = 10 ** 5 // Phi

file = open(f"testcases/in/01_test-{id}.txt", "w")
file.write(str(Phi) + "\n")

def call():
    file.write(os.popen(f"./gen-impl.exe {randint(0, 1 << 30)} {Q} {Max_xy}").read())

joblib.Parallel(n_jobs=1)(
    joblib.delayed(call)() for _ in [0] * Phi
)

file.close()
