func max(a,b int64) int64{
    if a >= b{
        return a
    }
    return b
}

func maximumTripletValue(nums []int) int64 {
    var m,t int64 = 0,0
    n := len(nums)
    for i:=0; i < n; i++{
        for j:=i+1; j < n; j++{
            for k:=j+1; k < n; k++{
                t = int64(nums[i]-nums[j])*int64(nums[k])
                m = max(m,t)
            }
        }
    }
    return m
}