from itertools import product
import os

import joblib

Args = []

for p in range(0, 5):
    for _ in [0] * (5 // (p+1) + 1):
        Args.append((10 ** p, 0, 0))
        Args.append((10 ** p, -1, 0))

print(len(Args))
print(Args)

def call(id, args):
    cmd = f"python3 tools/gen-call.py { id } { ' '.join(map(str, args)) }"
    os.popen(cmd)

joblib.Parallel(n_jobs=2)(
    joblib.delayed(call)(id, args) for id, args in enumerate(Args)
)
