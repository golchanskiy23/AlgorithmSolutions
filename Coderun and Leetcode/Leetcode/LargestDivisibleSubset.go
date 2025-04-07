func largestDivisibleSubset(nums []int) []int {
    n := len(nums)
    if n == 0 {return []int{}}

    sort.Ints(nums)
    dp, prev := make([]int, n), make([]int, n)

    maxIdx := 0

    for i := 0; i < n; i++ {
        dp[i] = 1
        prev[i] = -1
        for j := 0; j < i; j++ {
            if nums[i]%nums[j] == 0 && dp[j]+1 > dp[i] {
                dp[i] = dp[j] + 1
                prev[i] = j
            }
        }
        if dp[i] > dp[maxIdx] {maxIdx = i}
    }
    
    result := []int{}
    for maxIdx != -1 {
        result = append(result , nums[maxIdx])
        maxIdx = prev[maxIdx]
    }
    return result
}