// TODO: Consider rewriting trinomial methods
pub fn recursive_trinomial(n: i32, k: i32) -> i32 {
    if k.abs() == n {
        return 1;
    } else if k.abs() > n {
        return 0;
    }
    recursive_trinomial(n - 1, k - 1)
        + recursive_trinomial(n - 1, k)
        + recursive_trinomial(n - 1, k + 1)
}

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

    matrix[n as usize][k as usize]
}

pub fn dynamic_trinomial(n: i32, k: i32) -> i32 {
    let mut vec1 = vec![0; (n + 1) as usize];
    let mut vec2 = vec![0; (n + 1) as usize];

    for i in 0..=n {
        for j in 0..=n {
            if i == j {
                vec1[j as usize] = 1;
            } else if j < i {
                let val = vec2[(j - 1).abs() as usize] + vec2[j as usize] + vec2[(j + 1) as usize];
                vec1[j as usize] = val;
            }
        }
        vec1.swap_with_slice(&mut vec2);
    }

    vec2[k as usize]
}
