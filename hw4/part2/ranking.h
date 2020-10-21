#include <cstddef>

double* naive_rank(double* Adj_m, size_t n);
double* pagerank(double* Adj_m, double d, double eps, int max_it, size_t n);
