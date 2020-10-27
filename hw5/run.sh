#!/bin/bash
mpiexec -n 4 python task1.py | tee output_task1.txt
mpiexec -n 4 python task2_rule110_periodic.py | tee output_rule110_periodic.txt
mpiexec -n 4 python task2_rule110.py | tee output_rule110.txt
mpiexec -n 4 python task2_rule30_periodic.py | tee output_rule30_periodic.txt
