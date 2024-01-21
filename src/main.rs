mod binomial;
mod fibonacci;
mod trinomial;
mod lcslen;

fn main() {
    println!("fibonacci(5)");
    let arg = 5;

    println!("Recursive: {}", fibonacci::recursive_fibonacci(arg));
    println!("Array: {}", fibonacci::array_fibonacci(arg));
    println!("Dyanamic: {}", fibonacci::dynamic_fibonacci(arg));
    println!("==========");

    println!("binomial(5, 3)");
    let arg = (5, 3);

    println!("Recursive: {}", binomial::recursive_binomial(arg.0, arg.1));
    println!("Array: {}", binomial::matrix_binomial(arg.0, arg.1));
    println!("Dyanamic: {}", binomial::dynamic_binomial(arg.0, arg.1));
    println!("==========");

    println!("trinomial(5, 3)");
    let arg = (5, 3);

    println!("Recursive: {}", trinomial::recursive_trinomial(arg.0, arg.1));
    println!("Array: {}", trinomial::matrix_trinomial(arg.0, arg.1));
    println!("Dyanamic: {}", trinomial::dynamic_trinomial(arg.0, arg.1));
    println!("==========");

    println!("lcslen(TGCGTCCAT,  TACGTGCGCT)");
    let a = "TGCGTCCAT".chars().collect();
    let b = "TACGTGCGCT".chars().collect();

    println!("Recursive: {}", lcslen::recursive_lcslen(&a, &b, a.len(), b.len()));
    println!("Dyanamic: {}", lcslen::dynamic_lcslen(&a, &b));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_fibonacci() {
        let n = 5;

        assert_eq!(5, fibonacci::recursive_fibonacci(n));
        assert_eq!(5, fibonacci::array_fibonacci(n));
        assert_eq!(5, fibonacci::dynamic_fibonacci(n));
    }

    #[test]
    fn test_binomial() {
        let n = 5;
        let k = 3;

        assert_eq!(10, binomial::recursive_binomial(n, k));
        assert_eq!(10, binomial::matrix_binomial(n, k));
        assert_eq!(10, binomial::dynamic_binomial(n, k));
    }

    #[test]
    fn test_trinomial() {
        let n = 5;
        let k = 3;

        assert_eq!(15, trinomial::recursive_trinomial(n, k));
        assert_eq!(15, trinomial::matrix_trinomial(n, k));
        assert_eq!(15, trinomial::dynamic_trinomial(n, k));
    }

    #[test]
    fn test_lcslen() {
        let a = "TGCGTCCAT".chars().collect();
        let b = "TACGTGCGCT".chars().collect();

        assert_eq!(7, lcslen::recursive_lcslen(&a, &b, a.len(), b.len()));
        assert_eq!(7, lcslen::dynamic_lcslen(&a, &b));
    }
}
