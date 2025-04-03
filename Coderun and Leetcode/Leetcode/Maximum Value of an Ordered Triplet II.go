func Max(a,b int) int{
    if a >= b {return a}
    return b
}

func MaxInt64(a,b int64) int64{
    if a >= b {return a}
    return b
}

func maximumTripletValue(nums []int) int64 {
    n := len(nums)
    maxPrefix, maxSuffix := make([]int, n) , make([]int, n)
    maxPrefix[0], maxSuffix[n-1] = nums[0], nums[n-1]
    for i:=1; i < n; i++{
        maxPrefix[i] = Max(maxPrefix[i-1], nums[i])
    }

    for i:=n-2; i >= 0; i--{
        maxSuffix[i] = Max(maxSuffix[i+1], nums[i])
    }

    var ans int64 = 0
    for i := 1; i <= n-2; i++{
        ans = MaxInt64(ans, int64(maxPrefix[i-1]-nums[i])*int64(maxSuffix[i+1]))
    } 
    return ans
}