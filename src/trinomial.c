#include "trinomial.h"

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
  const int offset = n;

  int matrix[n][(2 * n) + 1];
  for (int i = 0; i < n; i++) {
    for (int j = -n; j <= n; j++) {
      if (abs(j) == i) {
        matrix[i][offset + j] = 1;
      } else if (abs(j) > i) {
        matrix[i][offset + j] = 0;
      } else {
        matrix[i][offset + j] = matrix[i - 1][offset + j - 1] +
                                matrix[i - 1][offset + j] +
                                matrix[i - 1][offset + j + 1];
      }
    }
  }
  return matrix[n - 1][offset + k - 1] + matrix[n - 1][offset + k] +
         matrix[n - 1][offset + k + 1];
}
