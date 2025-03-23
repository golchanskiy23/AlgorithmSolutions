func min(n1, n2 int) int{
    if n1 < n2{
        return n1
    }
    return n2
}

func minimumTotal(triangle [][]int) int {
    n := len(triangle)
    dp := make([]int, n+1)
    for i := n-1; i >= 0; i--{
        for j := 0; j <= i; j++{
            dp[j] = min(dp[j], dp[j+1])+triangle[i][j]
        }
    }
    return dp[0]
}