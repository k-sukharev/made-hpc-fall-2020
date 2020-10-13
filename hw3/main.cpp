#include <numeric>
#include <iostream>
#include <vector>

#include <omp.h>

const size_t N = 1e8;
const int N_THREADS = omp_get_max_threads();

std::vector<unsigned int> seeds(N_THREADS);

void seedThreads() {
    int my_thread_id;
    unsigned int seed;
    #pragma omp parallel private (seed, my_thread_id)
    {
        my_thread_id = omp_get_thread_num();
        unsigned int seed = (unsigned) time(NULL);
        seeds[my_thread_id] = (seed & 0xFFFFFFF0) | (my_thread_id + 1);
    }
}

double monte_carlo_pi(const size_t n) {
  double cnt = 0;
  int tid;
  unsigned int seed;

  #pragma omp parallel num_threads(N_THREADS) default(none) \
          private(tid, seed) \
          shared(n, seeds) \
          reduction(+:cnt)
  {
    tid = omp_get_thread_num();
    seed = seeds[tid];
    srand(seed);

    #pragma omp for
    for (size_t i = 0; i < n; ++i) {
      double x = (double)rand_r(&seed) / RAND_MAX - 0.5;
      double y = (double)rand_r(&seed) / RAND_MAX - 0.5;

      if (x * x + y * y < 0.25) {
        cnt += 1;
      }

    }

  }
  double proba = cnt / n;
  double pi = proba / 0.25;

  return pi;
}

int main() {
  seedThreads();

  double start = omp_get_wtime();
  double pi = monte_carlo_pi(N);
  double end = omp_get_wtime();

  std::cout << "pi = " << pi << "\n";
  std::cout << "number of threads: " << omp_get_max_threads() << "\n";
  std::cout << "runtime: " << end - start << " s\n\n";


  return 0;
}
