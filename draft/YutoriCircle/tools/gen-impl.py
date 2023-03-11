import os
from random import randint
import sys
import joblib

args = sys.argv

id = str(int(args[1])).zfill(4)
Phi = int(args[2])

file = open(f"testcases/in/01_test-{id}.txt", "w")
file.write(str(Phi) + "\n")

def call():
    file.write(f"{ randint(1, (1 << randint(1, 30)) - 1) }\n")

joblib.Parallel(n_jobs=1)(
    joblib.delayed(call)() for _ in [0] * Phi
)

file.close()
