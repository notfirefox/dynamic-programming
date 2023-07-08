#include "lcs.h"

#include <stdio.h>

static int max(const int x, const int y) { return x >= y ? x : y; }

int lcslen(const char x[], const char y[], const int i, const int j) {
  if (i == 0 || j == 0) {
    return 0;
  } else if (x[i] == y[j]) {
    return lcslen(x, y, i - 1, j - 1) + 1;
  }
  return max(lcslen(x, y, i - 1, j), lcslen(x, y, i, j - 1));
}

/* Dynamic */

void print_lcs(const int m, const int n, const int i, const int j,
               char b[m + 1][n + 1], const char x[m]) {
  if (i == 0 || j == 0) {
    return;
  }
  if (b[i][j] == 'Q') {
    print_lcs(m, n, i - 1, j - 1, b, x);
    printf("%c", x[i - 1]);
  } else if (b[i][j] == 'W') {
    print_lcs(m, n, i - 1, j, b, x);
  } else if (b[i][j] == 'A') {
    print_lcs(m, n, i, j - 1, b, x);
  }
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
