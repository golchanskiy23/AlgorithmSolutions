func max(a,b int64) int64{
    if a >= b{
        return a
    }
    return b
}

func dfs(questions [][]int, dp []int64, i int) int64{
    if i >= len(dp){
        return 0
    }
    if dp[i] != 0{
        return dp[i]
    }
    a, b := dfs(questions, dp, i+questions[i][1]+1)+int64(questions[i][0]) , dfs(questions, dp, i+1)
    dp[i] = max(a,b)
    return dp[i]
}

func mostPoints(questions [][]int) int64 {
    n := len(questions)
    dp := make([]int64, n)
    for i:= 0; i < n; i++{
        dfs(questions, dp,i)
    }
    var m int64
    for _, val := range dp{
        m = max(m,val)
    }
    return m
}