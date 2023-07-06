#include <stdio.h>

#include "binomial.h"
#include "fibonacci.h"
#include "function.h"
#include "trinomial.h"

int main(int argc, const char *argv[]) {
  // int result = dynamic_binomial(5, 3);
  // printf("%d\n", dynamic_result);
  int result = dynamic_function(5, 3);
  printf("%d\n", result);

  return 0;
}
