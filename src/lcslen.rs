pub fn recursive_lcslen(x: &Vec<char>, y: &Vec<char>, i: usize, j: usize) -> usize {
    if i == 0 || j == 0 {
        return 0;
    } else if (i == x.len() && j == y.len()) || x[i] == y[j] {
        return recursive_lcslen(x, y, i - 1, j - 1) + 1;
    }
    let val1 = recursive_lcslen(x, y, i - 1, j);
    let val2 = recursive_lcslen(x, y, i, j - 1);
    return val1.max(val2);
}

pub fn dynamic_lcslen(x: &Vec<char>, y: &Vec<char>, m: usize, n: usize) -> usize {
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
