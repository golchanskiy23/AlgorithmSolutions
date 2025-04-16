func countGood(nums []int, k int) int64 {
    m := make(map[int]int)
    var ans int64 = 0
    l, r, n, currPairs := 0,0, len(nums), 0
    for ; r < n; r++ {
        currPairs += m[nums[r]]
        m[nums[r]]++

        for currPairs >= k {
            ans += int64(n-r)
            m[nums[l]]--
            currPairs -= m[nums[l]]
            l++
        }
    }
    return ans
}