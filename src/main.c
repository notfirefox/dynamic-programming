#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binomial.h"
#include "fibonacci.h"
#include "function.h"
#include "lcs.h"
#include "trinomial.h"

int main(int argc, const char *argv[]) {
  const int n = 5;
  const int k = 3;

  const int x = binomial(n, k);
  const int y = binomial_matrix(n, k);
  const int z = dynamic_binomial(n, k);

  printf("%d\n", x);
  printf("%d\n", y);
  printf("%d\n", z);
  /*
  const char *const x = "TGCGTCCAT";
  const char *const y = "TACGTGCGCT";
  const int i = strlen(x);
  const int j = strlen(y);

  int length1 = lcslen(x, y, i, j);
  printf("%d\n", length1);

  char b[i + 1][j + 1];
  int length2 = dynamic_lcslen(x, y, i, j, b);
  printf("%d\n", length1);

  char result[length2];
  find_lcs(i, j, length2, result, b, x);
  printf("%s\n", result);
  */

  return 0;
}
