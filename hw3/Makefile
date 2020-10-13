CC=g++
CFLAGS=-fopenmp
SOURCE=main.cpp
EXECUTABLE=monte_carlo_pi

all: $(EXECUTABLE) corrected_bug_exec
$(EXECUTABLE):
	$(CC) $(CFLAGS) $(SOURCE) -o $@
corrected_bug_exec:
	gcc omp_bugparfor.c -o omp_bugparfor -fopenmp
	gcc omp_bugreduction.c -o omp_bugreduction -fopenmp
clean:
	rm -f $(EXECUTABLE) omp_bugparfor omp_bugreduction
