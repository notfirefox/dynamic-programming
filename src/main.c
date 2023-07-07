#include <stdio.h>

#include "binomial.h"
#include "fibonacci.h"
#include "function.h"
#include "trinomial.h"

int main(int argc, const char *argv[]) {
  int result = binomial(5, 3);
  printf("%d\n", result);

  int result2 = dynamic_binomial(5, 3);
  printf("%d\n", result2);

  return 0;
}
