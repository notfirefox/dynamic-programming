pub fn recursive_binomial(n: i32, k: i32) -> i32 {
    if n == k || k == 0 {
        return 1;
    }
    return recursive_binomial(n - 1, k - 1) + recursive_binomial(n - 1, k);
}

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
