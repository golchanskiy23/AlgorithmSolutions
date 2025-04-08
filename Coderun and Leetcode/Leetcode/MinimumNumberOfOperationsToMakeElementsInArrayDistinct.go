func minimumOperations(nums []int) int {
   arr, m := 0, make(map[int]int)
   for _, val := range nums{
    if _, ok := m[val]; ok == false {arr++}
    m[val]++
   }

    ans, curr_idx := 0, 0
    for arr != len(nums)-curr_idx{
        if len(nums)-curr_idx >= 3{
            for i := 0; i < 3; i++{
                m[nums[curr_idx]]--
                if m[nums[curr_idx]] == 0 {arr--}
                curr_idx++
            }
            ans++    
        } else{
            ans++
            break
        }
   }
   return ans
}