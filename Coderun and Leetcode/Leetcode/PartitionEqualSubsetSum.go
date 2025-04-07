func canPartition(nums []int) bool {
    sum, n := 0, len(nums)
    for i:=0; i < n; i++ { sum += nums[i] }
    if sum%2 != 0 {return false}
    dp := make([]int, sum+1)
    dp[0] = 1
    for i:=0; i < n; i++{
        for j := sum; j >= nums[i]; j--{
            dp[j] += dp[j-nums[i]]
        }
    }
    fmt.Print(dp)
    if dp[sum/2]%2 == 0 && dp[sum/2] !=0 {return true}
    return false
}