package main

import (
	"fmt"
)

func countDistinctPrimeFactors(x int64) int {
	count := 0
	if x%2 == 0 {
		count++
		for x%2 == 0 {
			x /= 2
		}
	}
	for i := int64(3); i*i <= x; i += 2 {
		if x%i == 0 {
			count++
			for x%i == 0 {
				x /= i
			}
		}
	}
	if x > 1 {
		count++
	}
	return count
}

func main() {
	var n int64
	fmt.Scan(&n)

	ans := 0
	for k := 0; k <= 40; k++ {
		x := n - int64(k)
		if x <= 0 {
			continue
		}
		if countDistinctPrimeFactors(x) == k {
			ans++
		}
	}
	fmt.Println(ans)
}