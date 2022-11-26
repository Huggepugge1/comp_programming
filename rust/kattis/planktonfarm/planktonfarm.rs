fn main() {
    let mut s: String = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let a: i32 = s.trim().parse().unwrap();
    s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let _b: i32 = s.trim().parse().unwrap();
    s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut c: Vec<i32> = s
        .split(' ')
        .map(|x| x.trim().parse().unwrap())
        .collect::<Vec<i32>>();
    c.sort();
    let mut p1=0;
    let mut p2=c.len() - 1;
    let mut ans=0;
    while p1 < p2 {
        if c[p1] * c[p2] >= a {
            p2 -= 1;
            ans += 1;
        }
        p1 += 1;
    }
    println!("{}", ans);
}
