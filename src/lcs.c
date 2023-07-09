#include "lcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int max(const int x, const int y) { return x >= y ? x : y; }

int lcslen(const char x[], const char y[], const int i, const int j) {
  if (i == 0 || j == 0) {
    return 0;
  } else if (x[i] == y[j]) {
    return lcslen(x, y, i - 1, j - 1) + 1;
  }
  return max(lcslen(x, y, i - 1, j), lcslen(x, y, i, j - 1));
}

int dynamic_lcslen(const char x[], const char y[], const int m, const int n,
                   char b[m + 1][n + 1]) {
  int c[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    c[i][0] = 0;
  }

  for (int j = 0; j <= n; j++) {
    c[0][j] = 0;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (x[i - 1] == y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 'Q';
      } else if (c[i - 1][j] >= c[i][j - 1]) {
        c[i][j] = c[i - 1][j];
        b[i][j] = 'W';
      } else {
        c[i][j] = c[i][j - 1];
        b[i][j] = 'A';
      }
    }
  }

  return c[m][n];
}

static void _find_lcs(const int m, const int n, const int i, const int j,
                      const int l, char result[l], int *index,
                      const char b[m + 1][n + 1], const char x[m]) {
  if (i == 0 || j == 0) {
    return;
  }
  if (b[i][j] == 'Q') {
    _find_lcs(m, n, i - 1, j - 1, l, result, index, b, x);
    result[(*index)++] = x[i - 1];
  } else if (b[i][j] == 'W') {
    _find_lcs(m, n, i - 1, j, l, result, index, b, x);
  } else if (b[i][j] == 'A') {
    _find_lcs(m, n, i, j - 1, l, result, index, b, x);
  }
}

void find_lcs(const int m, const int n, const char l, char result[l],
              const char b[m + 1][n + 1], const char x[m]) {
  int *result_index = malloc(sizeof(int));
  if (result_index == NULL) {
    printf("Memory allocation failed.");
    exit(EXIT_FAILURE);
    return;
  }
  *result_index = 0;
  _find_lcs(m, n, m, n, l, result, result_index, b, x);
  free(result_index);
}
