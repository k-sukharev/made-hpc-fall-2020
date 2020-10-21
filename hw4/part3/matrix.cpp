#include "vec.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <map>

double* generate_zero_matrix(size_t n) {
  double* matrix = new double[n * n];

  #pragma omp parallel for default(none) \
        shared(n, matrix)
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      matrix[i * n + j] = 0;
    }
  }
  return matrix;
}

double* matmul(double* A, double* B, size_t n) {
  double* C = generate_zero_matrix(n);
  #pragma omp parallel for default(none) \
        shared(n, A, B, C)
  for (size_t k = 0; k < n; ++k) {
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        C[i * n + j] += A[i * n + k] * B[k * n + j];
      }
    }
  }
  return C;
}

double* matpower(double* A, int power, size_t n) {
  assert (power >= 1);

  if (power == 1) {
    return A;
  }

  std::map<int, double*> powers_of_A;
  powers_of_A[1] = A;

  int p;
  for (p = 2; p < power; p *= 2) {
    powers_of_A[p] = matmul(A, A, n);
  }

  if (p >= power) {
    p /= 2;
  }

  while (power - p != 0) {
    int other_p = 1;

    while (other_p * 2 <= power - p) {
      other_p *= 2;
    }

    powers_of_A[p + other_p] = matmul(
      powers_of_A[p],
      powers_of_A[other_p],
      n
    );
    p += other_p;
  }

  for (auto kv_pair : powers_of_A) {
    if ((kv_pair.first != 1) && (kv_pair.first != power)) {
      delete[]kv_pair.second;
    }
  }

  return powers_of_A[power];
}

double* generate_random_adjacency_matrix(size_t n, double sparsity) {
  double* matrix = new double[n * n];
  srand(time(NULL));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      if (i == j) {
        matrix[i * n + j] = 0;
      } else {
        matrix[i * n + j] = rand() > RAND_MAX * sparsity;
      }
    }
  }
  return matrix;
}
