#!/usr/bin/python3

import matplotlib.pyplot as plt
from typing import List

data : List[float] = [0.000609, 0.000380, 0.000231, 0.000072]
procs : List[int] = [1, 2, 3, 4]

plt.bar(procs, data, width = 0.5, color = 'green')
plt.xticks(procs)
plt.xlabel("Num of proccesses")
plt.ylabel("Time, s")
plt.title("Lab 02")
plt.savefig("output.png")

plt.show()

# plt.show()
