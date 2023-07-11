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

int dynamic_trinomial(const int n, const int k) {
  int matrix[n + 1][n + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == j) {
        matrix[i][j] = 1;
      } else if (j > i) {
        matrix[i][j] = 0;
      } else {
        matrix[i][j] = matrix[i - 1][abs(j - 1)] + matrix[i - 1][abs(j)] +
                       matrix[i - 1][abs(j + 1)];
      }
    }
  }
  return matrix[n][k];
}
