import os
from random import randint
import sys
import joblib

args = sys.argv

id = str(int(args[1])).zfill(4)
N = int(args[2])

file = open(f"testcases/in/01_test-{id}.txt", "w")
file.write("1\n")

n = 0
if N == 0: n = 50
if N == -1: n = randint(2, 50)
file.write(os.popen(f"./tools/gen-impl.exe { randint(0, 1 << 30) } { n }").read())

file.close()
