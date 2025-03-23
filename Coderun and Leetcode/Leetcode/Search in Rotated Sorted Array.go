func search(nums []int, target int) int {
    n := len(nums)
    if n == 1{
        if nums[0] == target{
            return 0
        }
        return -1
    }
    l,r := 0, n-1


    for l <= r && l >= 0 && r >= 0 && l <= n-1 && r <= n-1{
        fmt.Println(l,r)
        mid := l+(r-l)/2
        if nums[l] == target{
            return l
        }
        if nums[r] == target{
            return r
        }
        if nums[mid] == target{
            return mid
        }
        if nums[l] < nums[mid]{
            if target < nums[mid] && target > nums[l]{
                r = mid-1
            } else{
                l = mid+1
            }
        } else {
            if target > nums[mid] && target < nums[r]{
                l = mid+1
            } else{
                r = mid-1
            }
        }
    }
    return -1
}