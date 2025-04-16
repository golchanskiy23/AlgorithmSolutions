package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func min(a,b int) int{
    if a < b{return a}
    return b
}

func main(){
    reader := bufio.NewReader(os.Stdin)
    var n int
    fmt.Fscanf(reader, "%d\n", &n)
    A,B,C := make([]int, n), make([]int, n), make([]int, n)
    for i := 0; i < n; i++{
        str, _ := reader.ReadString('\n')
        str = strings.TrimSpace(str)
        strs := strings.Split(str, " ")
        A[i], _ = strconv.Atoi(strs[0])
        B[i], _ = strconv.Atoi(strs[1])
        C[i], _ = strconv.Atoi(strs[2])
    }
    
    dp := make([]int, n+1)
    const INF = 1 << 30
    for i := range dp {
        dp[i] = INF
    }
    dp[0] = 0
    for i := 1; i <= n; i++{
        dp[i] = min(dp[i], dp[i-1]+A[i-1])
        if i >= 2{
            dp[i] = min(dp[i], dp[i-2]+B[i-2])
        }
        if i >= 3{
            dp[i] = min(dp[i], dp[i-3]+C[i-3])
        }
    }
    fmt.Print(dp[n])
}