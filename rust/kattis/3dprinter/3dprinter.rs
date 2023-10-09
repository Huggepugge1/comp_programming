use std::cmp::min;

fn main() {
    solve();
}

fn solve() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let n: i32 = line.trim().parse::<i32>().unwrap();
    
    let ans: i32 = rec(n, 0, n, 1, Vec::new());
    println!("{}", ans);
}

fn rec(goal: i32, day: i32, left: i32, printers: i32, memo: Vec<Vec<Vec<i32>>>) -> i32 {
    if left <= 0 {
        return day;
    }
    if day > goal {
        return day;
    }
    let mut m: i32 = 1000000;
    for printer in 0..(printers+1) {
        m = min(rec(goal, day + 1, left - printer, printers * 2 - printer, memo), m);
    }
    m
}
