#include "matvec.h"
#include "matmul.h"

#include <chrono>
#include <iostream>
#include <vector>

const std::vector<size_t> SIZES_OF_MATRIX = {512, 1024, 2048, 4096};
const size_t NUMBER_OF_RUNS = 5;

int main() {
  for (const size_t n : SIZES_OF_MATRIX) {
    std::cout << "size = " << n << std::endl;
    std::cout << std::endl;

    // matvec
    int64_t duration_ms, avg_time_ms = 0;

    for (size_t i = 0; i < NUMBER_OF_RUNS; ++i) {
      auto t1 = std::chrono::high_resolution_clock::now();

      double* A = generate_random_matrix(n);
      double* x = generate_random_vector(n);
      double* y = matvec(A, x, n);

      auto t2 = std::chrono::high_resolution_clock::now();
      duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
      avg_time_ms += duration_ms;

      std::cout << "matvec run " << i << ": ";
      std::cout << duration_ms << " ms" << std::endl;

      delete[]A;
      delete[]x;
      delete[]y;
    }
    avg_time_ms /= NUMBER_OF_RUNS;

    std::cout << "matvec avg. runtime: ";
    std::cout << avg_time_ms << " ms"<< std::endl;
    std::cout << std::endl;

    // matmul
    avg_time_ms = 0;

    for (size_t i = 0; i < NUMBER_OF_RUNS; ++i) {
      auto t1 = std::chrono::high_resolution_clock::now();

      double* A = generate_random_matrix(n);
      double* B = generate_random_matrix(n);
      double* C = matmul(A, B, n);

      auto t2 = std::chrono::high_resolution_clock::now();
      duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
      avg_time_ms += duration_ms;

      std::cout << "matmul run " << i << ": ";
      std::cout << duration_ms << " ms" << std::endl;

      delete[]A;
      delete[]B;
      delete[]C;
    }
    avg_time_ms /= NUMBER_OF_RUNS;

    std::cout << "matmul avg. runtime: ";
    std::cout << avg_time_ms << " ms"<< std::endl;
    std::cout << std::endl;
  }
  return 0;
}
