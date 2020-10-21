#include "matrix.h"
#include "vec.h"
#include <cmath>

double* naive_rank(double* Adj_m, size_t n) {
  double* ranking = generate_zero_vector(n);

  for (size_t j = 0; j < n; ++j) {
    for (size_t i = 0; i < n; ++i) {
      ranking[j] += Adj_m[i * n + j];
    }
  }

  return ranking;
}

double* pagerank(double* Adj_m, double d, double eps, int max_it, size_t n) {
  double* ranking = new double[n];
  for (size_t i = 0; i < n; ++i) {
    ranking[i] = 1.0 / n;
  }

  double* Adj_m_hat = new double[n * n];
  for (size_t j = 0; j < n; ++j) {
    int col_L1 = 0;

    for (size_t i = 0; i < n; ++i) {
      col_L1 += std::abs(Adj_m[i * n + j]);
    }

    if (col_L1) {
      for (size_t i = 0; i < n; ++i) {
        Adj_m_hat[i * n + j] = d * Adj_m[i * n + j] / col_L1 + (1 - d) / n;
      }
    } else {
      for (size_t i = 0; i < n; ++i) {
        Adj_m_hat[i * n + j] = d * Adj_m[i * n + j] + (1 - d) / n;
      }
    }
  }

  double* new_ranking;

  for (int i = 0; i < max_it; ++i) {
    new_ranking = matvec(Adj_m_hat, ranking, n);

    double L1 = L1_norm(new_ranking, n);

    for (size_t i = 0; i < n; ++i) {
      new_ranking[i] /= L1;
    }

    double* dif = new double[n];
    for (size_t i = 0; i < n; ++i) {
      dif[i] = ranking[i] - new_ranking[i];
    }

    double dif_norm = L1_norm(dif, n);

    delete[]ranking;
    delete[]dif;

    ranking = new_ranking;

    if (dif_norm < eps) {
      break;
    }
  }

  delete[]Adj_m_hat;
  return ranking;
}
