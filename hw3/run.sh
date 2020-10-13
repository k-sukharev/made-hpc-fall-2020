#!/bin/bash
MAX_THREADS=32
OUTPUT_FILE=output_monte_carlo.txt
make

rm -f $OUTPUT_FILE

for (( i=1; i<=$MAX_THREADS; i*=2 ))
do
  export OMP_NUM_THREADS=$i
  ./monte_carlo_pi | tee -a $OUTPUT_FILE
done

./omp_bugparfor | tee output_bugparfor.txt
./omp_bugreduction | tee output_bugreduction.txt

make clean
