package main

import (
    "bufio"
    "fmt"
    "os"
)

func max(a int, b int) int{
    if a > b {
        return a
    }
    return b
}

func main() {
    scanner := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var w,h,n int
    fmt.Fscan(scanner, &w,&h,&n)
    l,r := 0, max(w,h)*n

    for l < r{
        mid := l+(r-l)/2
        dip := (mid / w) * (mid / h);
        if (dip < n) {
            l = mid + 1;
        }  else {
            r = mid;
        }
    }
    fmt.Fprint(writer, r)
}
