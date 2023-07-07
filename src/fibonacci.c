#include "fibonacci.h"

int fibonacci(const int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci_array(const int n) {
  int array[n];
  array[0] = 0;
  array[1] = 1;

  for (int i = 2; i <= n; i++) {
    array[i] = array[i - 1] + array[i - 2];
  }
  return array[n];
}

int dynamic_fibonacci(const int n) {
  int x = 0;
  int y = 1;
  for (int i = 0; i < n; i++) {
    const int t = y;
    y += x;
    x = t;
  }
  return x;
}
