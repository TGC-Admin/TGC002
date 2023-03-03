from itertools import product
import os

import joblib

Args = []

for p, q in product((1, 2, 4, 6, 8, 10), range(1, 6)):
    Args.append((p, -1, 10 ** q))

print(len(Args))
print(Args)

def call(id, args):
    cmd = f"python3 tools/gen-call.py { id } { ' '.join(map(str, args)) }"
    os.popen(cmd)

joblib.Parallel(n_jobs=1)(
    joblib.delayed(call)(id, args) for id, args in enumerate(Args)
)
