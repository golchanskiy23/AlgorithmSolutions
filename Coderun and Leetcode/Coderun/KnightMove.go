package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n , m int
    fmt.Fscanf(reader, "%d %d\n", &n, &m)
    dp := make([][]int,n)
    for i:=0; i < n; i++ {dp[i] = make([]int, m)}
    
    dp[0][0]=1
    for i := 0; i < n; i++{
        for j := 0; j < m; j++{
           if i-2 >= 0 && j-1>=0 {dp[i][j] += dp[i-2][j-1]}
            if i-1 >= 0 && j-2>=0 {dp[i][j] += dp[i-1][j-2]}
        }
    }
    
    fmt.Print(dp[n-1][m-1])
}