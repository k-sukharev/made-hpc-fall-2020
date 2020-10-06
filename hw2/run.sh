#!/bin/bash
make
./mm_exec_g | tee output_g.txt
./mm_exec_O3 | tee output_O3.txt
make clean
