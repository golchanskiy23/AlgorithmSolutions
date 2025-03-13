package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y int
}

func preprocessHeights(points []Point) ([]int, []int) {
	n := len(points)
	prefixRise := make([]int, n)
	prefixFall := make([]int, n)

	for i := 1; i < n; i++ {
		diff := points[i].y - points[i-1].y
		prefixRise[i] = prefixRise[i-1] + int(math.Max(float64(0), float64(diff)))
		prefixFall[i] = prefixFall[i-1] + int(math.Max(float64(0), float64(-diff)))
	}

	return prefixRise, prefixFall
}

func getElevationGain(prefixRise, prefixFall []int, s, f int) int {
	if s < f {
		return prefixRise[f-1] - prefixRise[s-1] // Двигаемся вправо (учитываем подъёмы)
	} else {
		return prefixFall[s-1] - prefixFall[f-1] // Двигаемся влево (учитываем спуски)
	}
}

func main() {
	var N int
	fmt.Scan(&N)

	points := make([]Point, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&points[i].x, &points[i].y)
	}

	prefixRise, prefixFall := preprocessHeights(points)

	var M int
	fmt.Scan(&M)

	for i := 0; i < M; i++ {
		var s, f int
		fmt.Scan(&s, &f)
		fmt.Println(getElevationGain(prefixRise, prefixFall, s, f))
	}
}