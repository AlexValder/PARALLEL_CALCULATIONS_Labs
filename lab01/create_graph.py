#!/usr/bin/python3

import subprocess
import os

# compile file

# print(subprocess.run(["bash"], text=True, input="cmake -S Lab01 -B build").stdout)
# print()
# print(subprocess.run(["bash"], text=True, input="make -C build").stdout)
# print()

# run program

os.chdir("build-Lab01-Desktop-Default/")

OUTPUT_PATH = "output.txt"
CONFIG_PATH = "config.txt"

CONFIG_MODIFICATORS = [2**x for x in range(1)]

config_file = open(CONFIG_PATH, "w+")

for cm in CONFIG_MODIFICATORS:
    print(cm)
    config_file.writelines(f"SIZE=256\nMODE=k\nTHREADS={cm}\nMP_ON=0\nOUTPUT=output.txt\n")
    print(config_file.read())
    #os.system("./Lab01")


config_file.close()

# output_file = open(OUTPUT_PATH, "r+")
# print(output_file.read())
# output_file.close()
