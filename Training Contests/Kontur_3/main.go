package main

import (
	"bufio"
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func input(r *bufio.Reader, arr []int64) int64 {
	var sum int64 = 0
	str, _ := r.ReadString('\n')
	str = strings.TrimSpace(str)
	strs := strings.Split(str, " ")
	for i := 0; i < len(strs); i++ {
		arr[i], _ = strconv.ParseInt(strs[i], 10, 64)
		sum += arr[i]
	}
	return sum
}

func taskA(r *bufio.Reader) string {
	var n, t int64
	fmt.Fscanf(r, "%d %d\n", &n, &t)
	a, b := make([]int64, n), make([]int64, t)
	sum1, sum2 := input(r, a), input(r, b)
	if t < sum1 || t > sum2 {
		return "NO"
	}
	return "YES"
}

func getFactors(num int) []int {
	ans := []int{1}
	for i := 2; i*i <= num; i++ {
		if num%i == 0 {
			ans = append(ans, i)
			for num%i == 0 {
				num /= i
			}
		}
	}

	return ans
}

func SlidingWindowHelper(tmp, vals []rune, window, start int) int {
	cntStart := 0
	for i := 0; i < len(tmp); i = i + window {
		currSlice := tmp[i : i+window]
		for j := 0; j < len(currSlice); j++ {
			if currSlice[j] != vals[start] {
				cntStart++
			}
		}
		start = (i + 1) % 2
	}
	return cntStart
}

func slidingWindow(window int, arr []rune) int {
	tmp := make([]rune, len(arr))
	copy(tmp, arr)
	vals := []rune{'1', '0'}
	cntStart := SlidingWindowHelper(tmp, vals, window, 0)
	cntStart2 := SlidingWindowHelper(tmp, vals, window, 1)

	return Min(cntStart, cntStart2)
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func taskB(r *bufio.Reader) int {
	str, _ := r.ReadString('\n')
	str = strings.TrimSpace(str)
	arr := []rune(str)
	factors := getFactors(len(arr))
	min_ := 0
	for i := 0; i < len(arr); i++ {
		min_ = Min(slidingWindow(factors[i], arr), min_)
	}
	return min_
}

type rook struct {
	Cols         map[int64]int64
	Rows         map[int64]int64
	AdjColsTotal int64
	AdjRowsTotal int64
	ColsCount    int64
	RowsCount    int64
	N            int64
}

func (r *rook) calcAdjRows(x, n int64) int64 {
	var val int64
	if cnt := r.Rows[x-1]; cnt != 0 || x == 1 {
		val++
	}
	if cnt := r.Rows[x+1]; cnt != 0 || x == n-1 {
		val++
	}
	return val
}

func (r *rook) calcAdjCols(y, n int64) int64 {
	var val int64
	if cnt := r.Cols[y-1]; cnt != 0 || y == 1 {
		val++
	}
	if cnt := r.Cols[y+1]; cnt != 0 || y == n-1 {
		val++
	}
	return val
}

func ComponentsChanging(r *rook, x, y, n int64) int64 {
	var res int64 = 0
	if _, ok := r.Rows[x]; !ok {
		r.Rows[x] = 0
	}

	if _, ok := r.Cols[y]; !ok {
		r.Cols[y] = 0
	}

	adjRows, adjCols := r.calcAdjRows(x, n), r.calcAdjCols(y, n)
	if r.Rows[x] == 0 {
		switch adjRows {
		case 0:
			res += (r.RowsCount - r.AdjRowsTotal + 1)
		case 2:
			res -= (r.RowsCount - r.AdjRowsTotal + 1)
		}
	}

	if r.Cols[y] == 0 {
		switch adjCols {
		case 0:
			res += (r.ColsCount - r.AdjColsTotal + 1)
		case 2:
			res -= (r.ColsCount - r.AdjColsTotal + 1)
		}
	}

	return res
}

func (r *rook) updateAdd(x, y, n int64) {
	if r.Rows[x] == 0 {
		r.AdjRowsTotal += r.calcAdjRows(x, n)
		r.RowsCount++
	}
	if r.Cols[y] == 0 {
		r.AdjColsTotal += r.calcAdjCols(x, n)
		r.ColsCount++
	}

	r.Rows[x]++
	r.Cols[y]++
}

func (r *rook) updateRemove(x, y, n int64) {
	if r.Rows[x] == 1 {
		r.AdjRowsTotal -= r.calcAdjRows(x, n)
		r.RowsCount--
	}
	if r.Cols[y] == 1 {
		r.AdjColsTotal -= r.calcAdjCols(x, n)
		r.ColsCount--
	}

	r.Rows[x]--
	r.Cols[y]--
}

func taskC(r *bufio.Reader) {
	var n, q int64
	fmt.Fscanf(r, "%d %d\n", &n, &q)
	rooks := &rook{
		Cols:         make(map[int64]int64),
		Rows:         make(map[int64]int64),
		AdjColsTotal: 0,
		AdjRowsTotal: 0,
		ColsCount:    0,
		RowsCount:    0,
		N:            n,
	}

	var op string
	var x, y int64
	var connectedComponents, i int64 = 1, 0
	for ; q > 0; i++ {
		fmt.Fscanf(r, "%s %d %d\n", &op, &x, &y)
		if op == "+" {
			connectedComponents += ComponentsChanging(rooks, x, y, n)
			rooks.updateAdd(x, y, n)
		} else {
			rooks.updateRemove(x, y, n)
			connectedComponents += ComponentsChanging(rooks, x, y, n)
		}
		fmt.Println(connectedComponents)
	}
}

var charStates string = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ"

func MinInt64(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func MaxInt64(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func update(tree []int64, v, tl, tr, l, r, add int64) {
	if l > r {
		return
	}
	if tl == l && tr == r {
		tree[v] += add
	} else {
		tm := (tl + tr) / 2
		update(tree, v*2, tl, tm, l, MinInt64(r, tm), add)
		update(tree, v*2+1, tm+1, tr, MaxInt64(l, tm+1), r, add)
	}
}

func get(tree []int64, v, tl, tr, pos int64) int64 {
	if tl == tr {
		return tree[v]
	}
	tm := (tl + tr) / 2
	if pos <= tm {
		return tree[v] + get(tree, v*2, tl, tm, pos)
	} else {
		return tree[v] + get(tree, v*2+1, tm+1, tr, pos)
	}
}
func taskD(r *bufio.Reader) {
	var s string
	var q, left, right, val int64

	fmt.Fscan(r, &s, &q)
	n := int64(len(s))

	segTree := make([]int64, 4*n)

	for i := int64(0); i < q; i++ {
		fmt.Fscan(r, &left, &right, &val)
		update(segTree, 1, 0, n-1, left-1, right-1, val)
	}

	for i := int64(0); i < n; i++ {
		initCode := strings.Index(charStates, s[i:i+1])
		toAdd := get(segTree, 1, 0, n-1, i)
		newCode := (int64(initCode) + toAdd) % int64(len(charStates))
		fmt.Print(charStates[newCode : newCode+1])
	}
}

func binarySearchOnRange(arr []int, x1, x2 int) bool {
	low, high := 0, len(arr)-1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] >= 1 && arr[mid] <= x2 {
			return true
		} else if arr[mid] < x1 {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}

	return false
}

func taskE(r *bufio.Reader) string {
	var n int
	fmt.Fscan(r, &n)

	x := make(map[int][]int, n)
	y := make(map[int][]int, n)

	for i := 0; i < n; i++ {
		var xi, yi int
		fmt.Fscan(r, &xi, &yi)

		arr := x[xi]
		arr = append(arr, yi)
		x[xi] = arr

		arr = y[yi]
		arr = append(arr, xi)
		y[yi] = arr
	}

	for _, arr := range x {
		sort.Slice(arr, func(i, j int) bool {
			return arr[i] < arr[j]
		})
	}

	for _, arr := range y {
		sort.Slice(arr, func(i, j int) bool {
			return arr[i] < arr[j]
		})
	}

	var q, x0, y0 int
	fmt.Fscan(r, &q)

	for i := 0; i < q; i++ {
		var dir string
		var k int

		fmt.Fscan(r, &dir, &k)

		switch dir {
		case "U":
			if yi, inX := x[x0]; inX && binarySearchOnRange(yi, y0, y0+k) {
				return fmt.Sprintln("Stop ", i+1)
			}
			y0 += k

		case "D":
			if yi, inX := x[x0]; inX && binarySearchOnRange(yi, y0-k, y0) {
				return fmt.Sprintln("Stop ", i+1)
			}
			y0 -= k

		case "R":
			if xi, inY := y[y0]; inY && binarySearchOnRange(xi, x0, x0+k) {
				return fmt.Sprintln("Stop ", i+1)
			}
			x0 += k

		case "L":
			if xi, inY := y[y0]; inY && binarySearchOnRange(xi, x0-k, x0) {
				return fmt.Sprintln("Stop ", i+1)
			}
			x0 -= k
		}
	}

	return fmt.Sprintln("Complete")
}

func main() {
	
}
