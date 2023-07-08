#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binomial.h"
#include "fibonacci.h"
#include "function.h"
#include "lcs.h"
#include "trinomial.h"

int main(int argc, const char *argv[]) {
  const char *const x = "TGCGTCCAT";
  const char *const y = "TACGTGCGCT";
  const int i = strlen(x);
  const int j = strlen(y);

  int length1 = lcslen(x, y, i, j);
  printf("%d\n", length1);

  char b[i + 1][j + 1];
  int length2 = dynamic_lcslen(x, y, i, j, b);
  printf("%d\n", length1);
  print_lcs(i, j, i, j, b, x);
  printf("\n");

  char result[length2];
  find_lcs(i, j, length2, result, b, x);
  printf("%s\n", result);

  return 0;
}
