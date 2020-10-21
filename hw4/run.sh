#!/bin/bash
make -C part1
make -C part2
make -C part3
./part1/matpower | tee output_part1_matpower.txt
./part2/pagerank | tee output_part2_pagerank.txt
export OMP_NUM_THREADS=4
./part3/pagerank_optim | tee output_part3_pagerank_optim.txt
make clean -C part1
make clean -C part2
make clean -C part3
