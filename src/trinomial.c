#include "trinomial.h"

#include <stdio.h>
#include <stdlib.h>

int trinomial(const int n, const int k) {
  if (abs(k) == n) {
    return 1;
  } else if (abs(k) > n) {
    return 0;
  }
  return trinomial(n - 1, k - 1) + trinomial(n - 1, k) +
         trinomial(n - 1, k + 1);
}

int trinomial_matrix(const int n, const int k) {
  int matrix[n + 1][n + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == j) {
        matrix[i][j] = 1;
      } else if (j > i) {
        matrix[i][j] = 0;
      } else {
        matrix[i][j] =
            matrix[i - 1][abs(j - 1)] + matrix[i - 1][j] + matrix[i - 1][j + 1];
      }
    }
  }

  return matrix[n][k];
}

int dynamic_trinomial(const int n, const int k) {
  int array_1[n + 1];
  int array_2[n + 1];

  int *current = array_1;
  int *previous = array_2;
  for (int i = 0; i <= n; i++) {
    current = (current == array_1) ? array_2 : array_1;
    previous = (previous == array_1) ? array_2 : array_1;

    for (int j = 0; j <= n; j++) {
      if (i == j) {
        current[j] = 1;
      } else if (j > i) {
        current[j] = 0;
      } else {
        current[j] = previous[abs(j - 1)] + previous[j] + previous[j + 1];
      }
    }
  }

  return current[k];
}
