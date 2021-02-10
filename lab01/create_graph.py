#!/usr/bin/python3

import subprocess
import os
import matplotlib.pyplot as plt
from typing import List

# Collect info

OUTPUT_PATH : str = "build-Lab01-Desktop-Default/output.txt"
output_file = open(OUTPUT_PATH, "r")
raw_data : List[str] = output_file.read().split('\n')
output_file.close()

actual_data : List[float] = [float(x) for x in raw_data if x != '']

# Draw graph

plt.plot(actual_data, 'g-o', drawstyle='steps-mid', fillstyle='full')
plt.savefig('OUTPUT.png')
plt.show()

# plt.show()
