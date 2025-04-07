func max(a,b int) int{
    if a > b {return a}
    return b
}

func insert(intervals [][]int, newInterval []int) [][]int {
    intervals = append(intervals, newInterval)
    sort.Slice(intervals, func(i,j int) bool{
        return intervals[i][0] < intervals[j][0]
    })
    ans := make([][]int, 0)
    ans = append(ans, intervals[0])
    for i := 1; i < len(intervals); i++{
        if ans[len(ans)-1][1] < intervals[i][0]{
           ans = append(ans, intervals[i])
        } else{
            ans[len(ans)-1][1] = max(ans[len(ans)-1][1], intervals[i][1])
        }
    }
    return ans
}