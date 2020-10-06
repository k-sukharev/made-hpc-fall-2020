#include "matmul.h"

#include <stdlib.h>
#include <time.h>

double* generate_random_matrix(size_t n) {
  double* matrix = new double[n * n];
  srand(time(NULL));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      matrix[i * n + j] = rand() / RAND_MAX;
    }
  }
  return matrix;
}

double* generate_zero_matrix(size_t n) {
  double* matrix = new double[n * n];
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      matrix[i * n + j] = 0.0;
    }
  }
  return matrix;
}

double* matmul(double* A, double* B, size_t n) {
  double* C = generate_zero_matrix(n);
  for (size_t k = 0; k < n; ++k) {
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        C[i * n + j] += A[i * n + k] * B[k * n + j];
      }
    }
  }
  return C;
}
