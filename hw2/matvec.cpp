#include "matvec.h"

#include <stdlib.h>
#include <time.h>

double* generate_random_vector(size_t n) {
  double* vector = new double[n];
  srand(time(NULL));
  for (size_t i = 0; i < n; ++i) {
    vector[i] = rand() / RAND_MAX;
  }
  return vector;
}

double* generate_zero_vector(size_t n) {
  double* vector = new double[n];
  for (size_t i = 0; i < n; ++i) {
    vector[i] = 0.0;
  }
  return vector;
}

double* matvec(double* A, double* x, size_t n) {
  double* y = generate_zero_vector(n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
        y[i] += A[i * n + j] * x[j];
    }
  }
  return y;
}
