#!/bin/bash

for i in $(seq 1 30); do
  echo $i
  eval "./bin/main <  ./test/input/"$1".in > ./test/output/"$i".out"
done
