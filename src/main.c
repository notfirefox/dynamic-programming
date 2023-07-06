#include <stdio.h>

#include "binomial.h"
#include "fibonacci.h"
#include "trinomial.h"

int main(int argc, const char *argv[]) {
  // int result = dynamic_binomial(5, 3);
  // printf("%d\n", result);

  int result = dynamic_fibonacci(10); // 55
  printf("%d\n", result);

  return 0;
}
