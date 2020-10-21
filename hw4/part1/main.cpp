#include "matrix.h"
#include "vec.h"

#include <iostream>

int main() {

  size_t N = 16;
  int power = 3;
  double sparsity = 0.8;

  double* Adj_m = generate_random_adjacency_matrix(N, sparsity);
  double* Adj_m_powered;

  Adj_m_powered = matpower(Adj_m, power, N);

  std::cout << "Adjacency matrix:\n";

  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      std::cout << Adj_m[N * i + j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n";

  std::cout << "Matrix raised to the power of " << power << ":\n";
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      std::cout << Adj_m_powered[N * i + j] << " ";
    }
    std::cout << "\n";
  }

  delete[]Adj_m;

  if (power != 1) {
    delete[]Adj_m_powered;
  }

  return 0;
}
