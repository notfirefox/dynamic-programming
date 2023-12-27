# Dynamic Programming

## Fibonacci
The Fibonacci number $F_n$ can be calculated using 
the following formula where $F_0=0$ and $F_1=1$.
```math
F_n = F_{n-1} + F_{n-2}
```
This can be directly translated into the following Rust code using recursion:
```rust
pub fn recursive_fibonacci(n: i32) -> i32 {
    if n == 0 || n == 1 {
        return n;
    }
    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
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
The above graph demonstrates that the function call `recursive_fibonacci(5)` 
already involves a lot of redundant calculations, such as 
`recursive_fibonacci(3)` and `recursive_fibonacci(2)`. 
At this point we should take a step back. Lets reiterate 
what we already know. In order to calculate $F_{n+2}$ we need $F_{n+1}$ and 
$F_n$. A better approach than calculating $F_n$ using $F_{n-1}$ and $F_{n-2}$
would be to calculate it from the smallest piece we know, i.e. $F_0$ and 
$F_1$ and then $F_2$. The concept could be visualized as follows:

| $n$   | $0$ | $1$ | $2$     | $3$       | $4$     | $5$     |
|-------|-----|-----|---------|-----------|---------|---------|
| $F_n$ | $0$ | $1$ | $0+1=1$ | $1+1=2$   | $1+2=3$ | $2+3=5$ |

This way we don't need to calculate a subproblem multiple times. 
The code for a primitive calculation storing all calculated values 
could like as follows.
```rust
pub fn array_fibonacci(n: i32) -> i32 {
    let mut vector = vec![0; (n + 1) as usize];
    vector[0] = 0;
    vector[1] = 1;

    for i in 2..=n {
        let x = vector[(i - 1) as usize];
        let y = vector[(i - 2) as usize];
        vector[i as usize] = x + y;
    }

    return vector[n as usize];
}
```
At this point there is one more optimization that could me made regarding
its memory usage. In order to calculate $F_n$ we only need to store $F_{n-1}$
and $F_{n-2}$. So we do not to store the whole sequence of fibonacci numbers
inside of an array. So the final form would like this:
```rust
pub fn dynamic_fibonacci(n: i32) -> i32 {
    let mut x = 0;
    let mut y = 1;

    for _i in 0..n {
        let t = y;
        y += x;
        x = t;
    }

    return x;
}
```

## Binomial Coefficients
Binomial Coeeficients can be calculated using the following formula,
where $\binom{n}{0}=1$ and $\binom{n}{n}=1$.
```math
\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}
```

The naive approach would be using recursion:
```rust
pub fn recursive_binomial(n: i32, k: i32) -> i32 {
    if n == k || k == 0 {
        return 1;
    }
    return recursive_binomial(n - 1, k - 1) + recursive_binomial(n - 1, k);
}
```

The above recursive code can again be visualized using a graph.
```mermaid
graph TD;
    5C3(5C3);
    5C3-->5C3_4C2(4C2);
    5C3-->5C3_4C3(4C3);
    5C3_4C2-->5C3_4C2_3C1(3C1);
    5C3_4C2-->5C3_4C2_3C2(3C2);
    5C3_4C3-->5C3_4C3_3C2(3C2);
    5C3_4C3-->5C3_4C3_3C3(3C3);
    5C3_4C2_3C1-->5C3_4C2_3C1_2C0(2C0);
    5C3_4C2_3C1-->5C3_4C2_3C1_2C1(2C1);
    5C3_4C2_3C1_2C1-->5C3_4C2_3C1_2C1_1C0(1C0);
    5C3_4C2_3C1_2C1-->5C3_4C2_3C1_2C1_1C1(1C1);

    5C3_4C2_3C2-->5C3_4C2_3C2_2C1(2C1);
    5C3_4C2_3C2-->5C3_4C2_3C2_2C2(2C2);
    5C3_4C2_3C2_2C1-->5C3_4C2_3C2_2C1_1C0(1C0);
    5C3_4C2_3C2_2C1-->5C3_4C2_3C2_2C1_1C1(1C1);

    5C3_4C3_3C2-->5C3_4C3_3C2_2C1(2C1);
    5C3_4C3_3C2-->5C3_4C3_3C2_2C2(2C2);
    5C3_4C3_3C2_2C1-->5C3_4C3_3C2_2C1_1C0(1C0);
    5C3_4C3_3C2_2C1-->5C3_4C3_3C2_2C1_1C1(1C1);
```

Applying the learnings from above we can calculate the binomial coefficients
using a matrix:

| **$n \textbackslash k$** | $0$ | $1$ | $2$  | $3$  |
|:------------------------:|-----|-----|------|------|
| $0$                      | $1$ |     |      |      |
| $1$                      | $1$ | $1$ |      |      |
| $2$                      | $1$ | $2$ | $1$  |      |
| $3$                      | $1$ | $3$ | $3$  | $1$  |
| $4$                      | $1$ | $4$ | $6$  | $4$  |
| $5$                      | $1$ | $5$ | $10$ | $10$ |

The code for populating the matrix would look as follows.
```rust
pub fn matrix_binomial(n: i32, k: i32) -> i32 {
    let mut matrix = vec![vec![0; (k + 1) as usize]; (n + 1) as usize];

    for i in 1..=n {
        for j in 0..=k {
            if i == j || j == 0 {
                matrix[i as usize][j as usize] = 1;
            } else {
                let val = matrix[(i - 1) as usize][(j - 1) as usize] 
                        + matrix[(i - 1) as usize][(j) as usize];
                matrix[i as usize][j as usize] = val;
            }
        }
    }

    return matrix[n as usize][k as usize];
}
```

Now there is one more thing to consider. In order to calculate a row
$R_x$ with $x > 0$ we only need $R_{x-1}$. So in total
we only need one row $R_x$ to store the current values and one row
$R_{x-1}$ to access the previously calculated values.
```rust
pub fn dynamic_binomial(n: i32, k: i32) -> i32 {
    let mut vec1 = vec![0; (k + 1) as usize];
    let mut vec2 = vec![0; (k + 1) as usize];

    for i in 0..=n {
        for j in 0..=k {
            if i == j || j == 0 {
                vec1[j as usize] = 1;
            } else {
                vec1[j as usize] = vec2[(j - 1) as usize] + vec2[j as usize];
            }
        }
        vec1.swap_with_slice(&mut vec2);
    }

    return vec2[k as usize];
}
```

## Trinomial Coefficients
The trinomial coefficients can be calculated using the below function with 
$\binom{n}{k}_2=1$ if $|k|=n$ and $\binom{n}{k}_2=0$ if $|k|>n$.
```math
\binom{n}{k}_2 = \binom{n-1}{k-1}_2 + \binom{n-1}{k}_2 + \binom{n-1}{k+1}_2
```

Again the recursive code can be easily obtained from the mathematical formula.
```rust
pub fn recursive_trinomial(n: i32, k: i32) -> i32 {
    if k.abs() == n {
        return 1;
    } else if k.abs() > n {
        return 0;
    }
    return recursive_trinomial(n - 1, k - 1) 
         + recursive_trinomial(n - 1, k) 
         + recursive_trinomial(n - 1, k + 1);
}
```

This time we are going to skip the graph and we are looking straight
onto the matrix calculating the values. The matrix can be easily filled
by going row by row and column by column over it and applying the
aforementioned rules.

| $n\textbackslash k$ | $-3$ | $-2$ | $-1$ | $0$ | $1$ | $2$ | $3$ |
|---------------------|------|------|------|-----|-----|-----|-----|
|  $0$                | $0$  | $0$  | $0$  | $1$ | $0$ | $0$ | $0$ |
|  $1$                | $0$  | $0$  | $1$  | $1$ | $1$ | $0$ | $0$ |
|  $2$                | $0$  | $1$  | $2$  | $3$ | $2$ | $1$ | $0$ |
|  $3$                | $1$  | $3$  | $6$  | $7$ | $6$ | $3$ | $1$ |

Effectively you only need this half of the matrix:
| $n\textbackslash k$ | $0$ | $1$ | $2$ | $3$ |
|---------------------|-----|-----|-----|-----|
|  $0$                | $1$ | $0$ | $0$ | $0$ |
|  $1$                | $1$ | $1$ | $0$ | $0$ |
|  $2$                | $3$ | $2$ | $1$ | $0$ |
|  $3$                | $7$ | $6$ | $3$ | $1$ |

An example of how that could be done using code is shown below.
```rust
pub fn matrix_trinomial(n: i32, k: i32) -> i32 {
    let mut matrix = vec![vec![0; (n + 1) as usize]; (n + 1) as usize];

    for i in 0..=n {
        for j in 0..=n {
            if i == j {
                matrix[i as usize][j as usize] = 1;
            } else if j < i {
                let val = matrix[(i - 1) as usize][(j - 1).abs() as usize] 
                        + matrix[(i - 1) as usize][j as usize]
                        + matrix[(i - 1) as usize][(j + 1) as usize];
                matrix[i as usize][j as usize] = val;
            }
        }
    }

    return matrix[n as usize][k as usize];
}
```

The same memory optimizations from above can be applied here as well:
```rust
pub fn dynamic_trinomial(n: i32, k: i32) -> i32 {
    let mut vec1 = vec![0; (n + 1) as usize];
    let mut vec2 = vec![0; (n + 1) as usize];

    for i in 0..=n {
        for j in 0..=n {
            if i == j {
                vec1[j as usize] = 1;
            } else if j < i {
                let val = vec2[(j - 1).abs() as usize]
                        + vec2[j as usize]
                        + vec2[(j + 1) as usize];
                vec1[j as usize] = val;
            }
        }
        vec1.swap_with_slice(&mut vec2);
    }

    return vec2[k as usize];
}
```

## Longest Common Subsequence
Given two sequences $X=(x_1,...x_m)$ and $Y=(y_1,...,y_n)$, the
length of their longest common subsequence can be calculated using
the following formula.
```math
c[i,j]=
\begin{cases}
0,                       &\text{if $i=0$ or $j=0$}\\
c[i-1,j-1]+1,            &\text{if $i,j>0$ and $x_i=y_j$}\\
max(c[i-1,j], c[i,j-1]), &\text{if $i,j>0$ and $x_i\neq y_j$}
\end{cases}
```

Using the above formula we can successively populate a matrix.
| $c[i-1,j-1]$ | $c[i-1,j]$ |
|--------------|------------|
| $c[i,j-1]$   | $c[i,j]$   |

The code for calculating the length of the LCS could look something like this.
```rust
pub fn dynamic_lcslen(x: &Vec<char>, y: &Vec<char>) -> usize {
    let m = x.len();
    let n = y.len();

    let mut matrix = vec![vec![0; (n + 1) as usize]; (m + 1) as usize];

    for i in 1..=m {
        for j in 1..=n {
            if x[i - 1] == y[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else if matrix[i - 1][j] >= matrix[i][j - 1] {
                matrix[i][j] = matrix[i - 1][j];
            } else {
                matrix[i][j] = matrix[i][j - 1];
            }
        }
    }

    return matrix[m][n];
}
```
