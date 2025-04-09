func minOperations(nums []int, k int) int {
    m := make(map[int]int)
    for i:= 0; i < len(nums); i++{
        if nums[i] < k{return -1}
        m[nums[i]]++
    }

    op := 0
    for key,_ := range m{
        if key != k {op++}
    }
    return op
}