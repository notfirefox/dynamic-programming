use std::vec;

pub fn recursive_fibonacci(n: usize) -> usize {
    if n == 0 || n == 1 {
        return n;
    }
    recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2)
}

pub fn array_fibonacci(n: usize) -> usize {
    let mut vector = vec![0; n + 1];
    vector[0] = 0;
    vector[1] = 1;

    for i in 2..=n {
        let x = vector[i - 1];
        let y = vector[i - 2];
        vector[i] = x + y;
    }

    vector[n]
}

pub fn dynamic_fibonacci(n: usize) -> usize {
    let mut x = 0;
    let mut y = 1;

    for _i in 0..n {
        let t = y;
        y += x;
        x = t;
    }

    x
}
