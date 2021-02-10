#!/bin/bash

echo 'Hi'
cd 'build-Lab01-Desktop-Default'

if [ -f output.txt ]; then
   rm output.txt
fi

cat config.txt
for i in {1..16}
do
    sed -i "s/^THREADS=.*/THREADS=${i}/" config.txt
    $'./Lab01'
done

cd '..'
$'./create_graph.py'
