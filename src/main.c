#include <stdio.h>

#include "binomial.h"
#include "trinomial.h"

int main(int argc, const char *argv[]) {
  // int result = dynamic_binomial_v2(5, 3);
  int result = dynamic_binomial_v2(9, 3);
  printf("%d\n", result);

  return 0;
}
