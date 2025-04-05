func dfs(nums []int, res *[]int, idx, currSum int){
    *res = append(*res, currSum)
    for i := idx; i < len(nums); i++{
        currSum ^= nums[i]
        fmt.Printf("dfs: %d %d %v\n", i+1, currSum, res)
        dfs(nums, res, i+1, currSum)

        currSum ^= nums[i]
    }
}

func subsetXORSum(nums []int) int {
    var res []int
    dfs(nums, &res, 0, 0)
    ans := 0
    for i := 0; i < len(res); i++ {ans += res[i]}
    return ans
}