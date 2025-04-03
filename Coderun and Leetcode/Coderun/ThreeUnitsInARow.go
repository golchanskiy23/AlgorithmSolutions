package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    scanner := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int
    fmt.Fscan(scanner, &n)
    dp := make([]int, 36)
    dp[0], dp[1], dp[2] = 1,2,4
    for i := 3; i <= 35; i++{
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])
    }
    fmt.Fprint(writer, dp[n])
}
