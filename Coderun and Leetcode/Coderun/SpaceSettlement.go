package main

import (
	"fmt"
	"math"
)

func max(a,b int) int{
    if a > b{
        return a
    }
    return b
}

func canFit(n, a, b, w, h, d int) bool {
	modWidth := a + 2*d
	modHeight := b + 2*d

	maximum := max((w/modWidth)*(h/modHeight), (w/modHeight)*(h/modWidth))

	return maximum >= n
}

func main() {
	var n, a, b, w, h int
	fmt.Scanf("%d %d %d %d %d", &n, &a, &b, &w, &h)

	low, high := 0, int(math.Max(float64((w-a)/2), float64((h-b)/2)))

	var answer int

	for low <= high {
		mid := (low + high) / 2
		if canFit(n, a, b, w, h, mid) {
			answer = mid
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	
	fmt.Println(answer)
}