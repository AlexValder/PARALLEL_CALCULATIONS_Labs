#!/bin/bash

echo 'Please enter how much memory you want to give to each scalar (number only): '
read memory_num
echo 'Please enter b for bytes, k for KiB, m for MiB or g for GiB: '
read mode_val
echo 'Please enter the maximum number of threads you want to give for calculations: '
read thread_num

cmake -S 'Lab01' -B 'build'
cd 'build'
make

printf "SIZE=${memory_num}\nMODE=${mode_val}\nTHREADS=0\nMP_ON=1\nOUTPUT=output.txt\n" > 'config.txt'

if [ -f output.txt ]; then
   rm output.txt
fi

cat config.txt
for ((i = 1; i <= thread_num; i++))
do
    sed -i "s/^THREADS=.*/THREADS=${i}/" config.txt
    $'./Lab01'
done

cd '..'
$'./create_graph.py'
