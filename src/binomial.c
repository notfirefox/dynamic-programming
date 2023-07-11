#include "binomial.h"

#include <stdio.h>
#include <stdlib.h>

int binomial(const int n, const int k) {
  if (n == k || k == 0) {
    return 1;
  }
  return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

int binomial_matrix(const int n, const int k) {
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

int dynamic_binomial(const int n, const int k) {
  int array_1[k + 1];
  int array_2[k + 1];

  int *current = array_1;
  int *previous = array_2;
  for (int i = 0; i <= n; i++) {
    current = (current == array_1) ? array_2 : array_1;
    previous = (previous == array_1) ? array_2 : array_1;

    for (int j = 0; j <= i; j++) {
      if (i == j || j == 0) {
        current[j] = 1;
      } else {
        current[j] = previous[j - 1] + previous[j];
      }
    }
  }

  return current[k];
}
