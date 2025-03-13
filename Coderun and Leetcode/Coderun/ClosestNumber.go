package main

import (
    "bufio"
    "fmt"
    "os"
)

func AbsInt(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n,tmp int
    fmt.Fscan(reader, &n)
    ans := make([]int,n)
    for i := 0; i < n; i++{
        fmt.Fscan(reader, &tmp)
        ans[i] = tmp
    }
    var t int
    diff,a := 1000000, 1000000
    fmt.Fscan(reader,&t)
    for i := 0; i < n; i++{
        if diff > AbsInt(ans[i]-t){
            diff = AbsInt(ans[i]-t)
            a = ans[i]
        }
    }
    fmt.Fprintln(writer, a)
}