#include <stdlib.h>
#include <cmath>

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

double L1_norm(double* x, size_t n) {
  double L1 = 0.0;

  for (size_t i = 0; i < n; ++i) {
    L1 += std::abs(x[i]);
  }

  return L1;
}
