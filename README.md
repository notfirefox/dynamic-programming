# Dynamic Programming

## Chapters
- Fibonacci
- Binomial Coefficients
- Trinomial Coefficients

## Fibonacci
The Fibonacci number $F_n$ can be calculated using the following formula where $F_0=0$ and $F_1=1$.
```math
F_n = F_{n-1} + F_{n-2}
```
This can be directly translated into the following C code using recursion:
```C
int fibonacci(const int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}
```
The code is easily comprehensible, but the runtime of it is rather poor.
```mermaid
graph TD;
    F5(F5);
    F5-->F5_F4(F4);
    F5-->F5_F3(F3);
    F5_F4-->F5_F4_F3(F3);
    F5_F4-->F5_F4_F2(F2);
    F5_F4_F3-->F5_F4_F3_F2(F2);
    F5_F4_F3-->F5_F4_F3_F1(F1);
    F5_F4_F3_F2-->F5_F4_F3_F2_F1(F1);
    F5_F4_F3_F2-->F5_F4_F3_F2_F0(F0);
    F5_F4_F2-->F5_F4_F2_F1(F1);
    F5_F4_F2-->F5_F4_F2_F0(F0);
    F5_F3-->F5_F3_F2(F2);
    F5_F3-->F5_F3_F1(F1);
    F5_F3_F2-->F5_F3_F2_F1(F1);
    F5_F3_F2-->F5_F3_F2_F0(F0);
```
The above graph demonstrates that the function call `fibonacci(5)` already involves a
lot of redundant calculations, such as `fibonacci(3)` and `fibonacci(2)`. At this point we should 
take a step back. Lets reiterate what we already know. In order to calculate $F_{n+2}$ we need
$F_{n+1}$ and $F_n$. A better approach than calculating $F_n$ using $F_{n-1}$ and $F_{n-2}$
would be to calculate it from the smallest piece we know, i.e. $F_0$ and $F_1$ and then $F_2$.
The concept could be visualized as follows:

<!-- TODO: This graph currently looks very messy. Look into ways to improve its appearance -->
```mermaid
graph LR;
  F0-->F2;
  F1-->F2;
  F1-->F3;
  F2-->F3;
  F2-->F4;
  F3-->F4;
  F3-->F5;
  F4-->F5;
```
This way we don't need to calculate a subproblem multiple times. The code for a primitive
calculation storing all calculated values could like as follows.
```C
int fibonacci_array(const int n) {
  int array[n];
  array[0] = 0;
  array[1] = 1;

  for (int i = 2; i <= n; i++) {
    array[i] = array[i - 1] + array[i - 2];
  }
  return array[n];
}
```

WIP

## Binomial Coefficients
WIP
```math
\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}
```

## Trinomial Coefficients
WIP
```math
\binom{n}{k}_2 = \binom{n-1}{k-1}_2 + \binom{n-1}{k}_2 + \binom{n-1}{k+1}_2
```
