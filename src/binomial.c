#include "binomial.h"

#include <stdio.h>
#include <stdlib.h>

int binomial(const int n, const int k) {
  if (n == k || k == 0) {
    return 1;
  }
  return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

int dynamic_binomial(const int n, const int k) {
  int matrix[n + 1][k + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (i == j || j == 0) {
        matrix[i][j] = 1;
      } else {
        matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
      }
    }
  }

  return matrix[n][k];
}
