pub fn recursive_binomial(n: usize, k: usize) -> usize {
    if n == k || k == 0 {
        return 1;
    }
    recursive_binomial(n - 1, k - 1) + recursive_binomial(n - 1, k)
}

pub fn matrix_binomial(n: usize, k: usize) -> usize {
    let mut matrix = vec![vec![0; k + 1]; n + 1];

    for i in 1..=n {
        for j in 0..=k {
            if i == j || j == 0 {
                matrix[i][j] = 1;
            } else {
                let val = matrix[i - 1][j - 1] + matrix[i - 1][j];
                matrix[i][j] = val;
            }
        }
    }

    matrix[n][k]
}

pub fn dynamic_binomial(n: usize, k: usize) -> usize {
    let mut vec1 = vec![0; k + 1];
    let mut vec2 = vec![0; k + 1];

    for i in 0..=n {
        for j in 0..=k {
            if i == j || j == 0 {
                vec1[j] = 1;
            } else {
                vec1[j] = vec2[j - 1] + vec2[j];
            }
        }
        vec1.swap_with_slice(&mut vec2);
    }

    vec2[k]
}
