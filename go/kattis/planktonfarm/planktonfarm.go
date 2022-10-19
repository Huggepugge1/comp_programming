package main

import (
    "bufio"
    "fmt"
    "sort"
    "os"
)

var in, out = bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)

func main() {
    a := _readInt()
    b := _readInt()
    
    c := make([]int, 1000000)
    for i := 0; i < b; i++ {
        c[i] = _readInt()
    }

    sort.Ints(c)

    var p1, p2, ans = 0, 999999, 0

    for p1 < p2 {
        if c[p1] * c[p2] >= a {
            p2--
            ans++
        }
        p1++
    }

    fmt.Printf("%d", ans)
}

func _readInt() int {
    var x int
    fmt.Fscan(in, &x)
    return x
}
