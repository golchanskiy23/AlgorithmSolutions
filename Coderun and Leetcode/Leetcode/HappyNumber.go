func divideIntoDigits(n int) []int{
    var curr int
    res := make([]int, 0)
    for n > 0{
        curr = n%10
        res = append(res, curr*curr)
        n /= 10
    }
    return res
}

func accumulate(arr []int) int{
    var ans int = 0
    for i := 0; i < len(arr); i++ {ans += arr[i]}
    return ans
}

func isHappy(n int) bool {
    vis := make(map[int]bool)
	for n != 1 && !vis[n] {
		vis[n] = true
		n= accumulate(divideIntoDigits(n))
	}
	return n == 1
}