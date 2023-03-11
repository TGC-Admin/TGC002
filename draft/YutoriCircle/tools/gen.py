from itertools import product
import os

import joblib

def call(id, phi):
    cmd = f"python3 tools/gen-impl.py { id } { phi }"
    os.popen(cmd)

joblib.Parallel(n_jobs=2)(
    joblib.delayed(call)(id, 100000) for id in range(20)
)
