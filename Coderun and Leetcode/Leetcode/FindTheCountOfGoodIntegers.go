func countGoodIntegers(n int, k int) int64 {
	base := int(math.Pow(10, float64((n-1)/2)))
	m := make(map[string]struct{})
	isOdd := n & 1
	for i := base; i < base*10; i++ {
		s := strconv.Itoa(i)

		runes := []rune(s)
		var reversed []rune
		for j := len(runes) - 1 - isOdd; j >= 0; j-- {
			reversed = append(reversed, runes[j])
		}

		palindrome := s + string(reversed)
		num, _ := strconv.ParseInt(palindrome, 10, 64)
		if num%int64(k) == 0 {
			palRunes := []rune(palindrome)
			sort.Slice(palRunes, func(i, j int) bool {
				return palRunes[i] < palRunes[j]
			})
			str := string(palRunes)
			if _, ok := m[str]; !ok {
				m[str] = struct{}{}
			}
		}
	}

	factorial := make([]int, 11)
	factorial[0] = 1
	for i := 1; i <= 10; i++ {
		factorial[i] = factorial[i-1] * i
	}

	var ans int64 = 0
	for val, _ := range m {
		cnt := make([]int, 10)
		for _, ch := range val {
			cnt[int(ch-'0')]++
		}

		total := (n-cnt[0])*factorial[n-1]
		for _, c := range cnt {
			total /= factorial[c]
		}

		ans += int64(total)
	}
	return ans
}