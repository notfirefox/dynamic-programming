mod binomial;
mod fibonacci;
mod trinomial;
mod lcslen;

fn main() {
    let n = 5;

    println!("fibonacci({})", n);

    let x = fibonacci::recursive_fibonacci(n);
    let y = fibonacci::array_fibonacci(n);
    let z = fibonacci::dynamic_fibonacci(n);

    println!("{}", x);
    println!("{}", y);
    println!("{}", z);

    // =======================================

    let n = 5;
    let k = 3;

    println!("binomial({}, {})", n, k);

    let x = binomial::recursive_binomial(n, k);
    let y = binomial::matrix_binomial(n, k);
    let z = binomial::dynamic_binomial(n, k);

    println!("{}", x);
    println!("{}", y);
    println!("{}", z);

    // =======================================

    let n = 5;
    let k = 3;

    println!("trinomial({}, {})", n, k);

    let x = trinomial::recursive_trinomial(n, k);
    let y = trinomial::matrix_trinomial(n, k);
    let z = trinomial::dynamic_trinomial(n, k);

    println!("{}", x);
    println!("{}", y);
    println!("{}", z);

    // =======================================

    // TCG TCC T
    let a = "TGCGTCCAT";  // len = 09
    let b = "TACGTGCGCT"; // len = 10

    println!("lcslen({}, {})", a, b);

    let a = a.chars().collect();
    let b = b.chars().collect();

    let x = lcslen::recursive_lcslen(&a, &b, a.len(), b.len());
    let y = lcslen::dynamic_lcslen(&a, &b);

    println!("{}", x);
    println!("{}", y);
}
