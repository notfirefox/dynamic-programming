use std::vec;

pub fn recursive_fibonacci(n: i32) -> i32 {
    if n == 0 || n == 1 {
        return n;
    }
    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

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
