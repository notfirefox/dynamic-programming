#include <stdio.h>

#include "binomial.h"
#include "fibonacci.h"
#include "function.h"
#include "trinomial.h"

int main(int argc, const char *argv[]) {
  int result = fibonacci(10);
  printf("%d\n", result);

  int result2 = fibonacci_array(10);
  printf("%d\n", result2);

  return 0;
}
