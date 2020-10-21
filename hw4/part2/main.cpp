#include "matrix.h"
#include "ranking.h"
#include "vec.h"

#include <chrono>
#include <iostream>

const size_t NUMBER_OF_RUNS = 5;
const size_t N = 2048;
const double SPARSITY = 0.8;
const double DUMPING_FACTOR = 0.85;
const double EPS = 0.001;
const int MAX_ITER = 1000;
const bool VERBOSE = false;

int main() {
  int64_t duration_ms, avg_time_naive_ms= 0, avg_time_pagerank_ms = 0;

  for (size_t run_idx = 0; run_idx < NUMBER_OF_RUNS; ++run_idx) {
    double* Adj_m = generate_random_adjacency_matrix(N, SPARSITY);

    if (VERBOSE) {
      std::cout << "Adjacency matrix:\n";

      for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
          std::cout << Adj_m[N * i + j] << " ";
        }
        std::cout << "\n";
      }
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    double* naive_ranking = naive_rank(Adj_m, N);
    auto t2 = std::chrono::high_resolution_clock::now();

    if (VERBOSE) {
      std::cout << "\n";
      std::cout << "Naive ranking:" << "\n";;
      for (size_t i = 0; i < N; ++i) {
        std::cout << naive_ranking[i] << " ";
      }
      std::cout << "\n";
    }

    delete[]Adj_m;
    delete[]naive_ranking;

    duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    avg_time_naive_ms += duration_ms;

    std::cout << "Naive ranking run " << run_idx << ": ";
    std::cout << duration_ms << " ms" << "\n";
  }

  std::cout << "\n";

  avg_time_naive_ms /= NUMBER_OF_RUNS;

  for (size_t run_idx = 0; run_idx < NUMBER_OF_RUNS; ++run_idx) {

    double* Adj_m = generate_random_adjacency_matrix(N, SPARSITY);

    if (VERBOSE) {
      std::cout << "Adjacency matrix:\n";

      for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
          std::cout << Adj_m[N * i + j] << " ";
        }
        std::cout << "\n";
      }
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    double* pagerank_ranking = pagerank(Adj_m, DUMPING_FACTOR, EPS, MAX_ITER, N);
    auto t2 = std::chrono::high_resolution_clock::now();

    if (VERBOSE) {
      std::cout << "\n";
      std::cout << "Pagerank:" << "\n";;
      for (size_t i = 0; i < N; ++i) {
        std::cout << pagerank_ranking[i] << " ";
      }
      std::cout << "\n";
    }

    delete[]Adj_m;
    delete[]pagerank_ranking;

    duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    avg_time_pagerank_ms += duration_ms;

    std::cout << "Pagerank run " << run_idx << ": ";
    std::cout << duration_ms << " ms" << "\n";
  }

  std::cout << "\n";

  avg_time_pagerank_ms /= NUMBER_OF_RUNS;

  std::cout << "Naive ranking avg. runtime: ";
  std::cout << avg_time_naive_ms << " ms"<< "\n";
  std::cout << "\n";

  std::cout << "Pagerank avg. runtime: ";
  std::cout << avg_time_pagerank_ms << " ms"<< "\n";
  std::cout << "\n";
}
