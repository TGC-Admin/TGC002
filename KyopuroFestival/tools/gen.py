from itertools import product
import os

import joblib

Args = []

for _ in [0] * 100:
    Args.append(0)
    Args.append(-1)

print(len(Args))
print(Args)

def call(id, arg):
    cmd = f"python3 tools/gen-call.py { id } { arg }"
    os.popen(cmd)

joblib.Parallel(n_jobs=2)(
    joblib.delayed(call)(id, args) for id, args in enumerate(Args)
)
