package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

const M float64 = 1e9
const delta = 1e-6

func InputN(scanner *bufio.Reader) int {
	nLine, _ := scanner.ReadString('\n')
	nLine = strings.TrimSpace(nLine)
	n, _ := strconv.Atoi(nLine)
	return n
}

func InputNArray(scanner *bufio.Reader) []int {
	str, _ := scanner.ReadString('\n')
	str = strings.TrimSpace(str)
	nums := strings.Split(str, " ")
	var arr = make([]int, 0)
	for i := 0; i < len(nums); i++ {
		num, _ := strconv.Atoi(nums[i])
		arr = append(arr, num)
	}
	return arr
}

func InputN64Array(scanner *bufio.Reader) []int64 {
	str, _ := scanner.ReadString('\n')
	str = strings.TrimSpace(str)
	nums := strings.Split(str, " ")
	var arr = make([]int64, 0)
	for i := 0; i < len(nums); i++ {
		num, _ := strconv.ParseInt(nums[i], 10, 64)
		arr = append(arr, num)
	}
	return arr
}

func task1() {
	scanner := bufio.NewReader(os.Stdin)
	number := InputN(scanner)
	var arr = make([]int, number)
	for i := 0; i < len(arr); i++ {
		_, err := fmt.Scan(&arr[i])
		if err != nil {
			log.Fatal(err)
		}
	}
	sort.Ints(arr)
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%d ", arr[i])
	}
}

func CountingSort(arr *[]int) {
	a := make([]int, 101)
	for i := 0; i < len(*arr); i++ {
		a[(*arr)[i]]++
	}
	k := 0
	for i := 0; i < len(a); i++ {
		for a[i] > 0 {
			(*arr)[k] = i
			k++
			a[i]--
		}
	}
}

func task2() {
	scanner := bufio.NewReader(os.Stdin)
	arr := InputNArray(scanner)
	CountingSort(&arr)
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%d ", arr[i])
	}
}

func countAndMerge(arr []int, l, m, r int) int {
	n1 := m - l + 1
	n2 := r - m

	left := make([]int, n1)
	right := make([]int, n2)

	copy(left, arr[l:m+1])
	copy(right, arr[m+1:r+1])

	i, j, k, res := 0, 0, l, 0

	for i < n1 && j < n2 {
		if left[i] <= right[j] {
			arr[k] = left[i]
			i++
		} else {
			arr[k] = right[j]
			j++
			res += n1 - i
		}
		k++
	}

	for i < n1 {
		arr[k] = left[i]
		i++
		k++
	}
	for j < n2 {
		arr[k] = right[j]
		j++
		k++
	}

	return res
}

func countInv(arr []int, l, r int) int {
	if l >= r {
		return 0
	}
	m := (l + r) / 2
	res := countInv(arr, l, m)
	res += countInv(arr, m+1, r)
	res += countAndMerge(arr, l, m, r)
	return res
}

func inversionCount(arr []int, n int) int {
	return countInv(arr, 0, n-1)
}

func task3() int {
	// for NlogN using mergeSort algorithm
	scanner := bufio.NewReader(os.Stdin)
	n := InputN(scanner)
	ans := inversionCount(InputNArray(scanner), n)
	return ans
}

type Heap struct {
	buffer []int
	size   int
}

// insert
func (h *Heap) Insert(v int) {
	h.buffer = append(h.buffer, v)
	h.size++
	i := h.size - 1
	for i > 0 && h.buffer[i] > h.buffer[(i-1)/2] {
		h.buffer[i], h.buffer[(i-1)/2] = h.buffer[(i-1)/2], h.buffer[i]
		i = (i - 1) / 2
	}
}

func (h Heap) GetMax() int {
	return h.buffer[0]
}

// getMin and remove
func (h *Heap) Extract() int {
	smallest := h.GetMax()
	h.buffer[0], h.buffer[h.size-1] = h.buffer[h.size-1], h.buffer[0]
	h.size--
	h.buffer = h.buffer[:h.size]
	currIdx := 0
	for h.size > 2*currIdx+1 {
		potential := 2*currIdx + 1
		if 2*currIdx+2 < h.size && h.buffer[potential] < h.buffer[2*currIdx+2] {
			potential = 2*currIdx + 2
		}
		if h.buffer[potential] > h.buffer[currIdx] {
			h.buffer[potential], h.buffer[currIdx] = h.buffer[currIdx], h.buffer[potential]
		} else {
			break
		}
		currIdx = potential
	}
	return smallest
}

func task4() {
	scanner := bufio.NewReader(os.Stdin)
	n := InputN(scanner)
	heap := &Heap{}
	for i := 0; i < n; i++ {
		input := InputNArray(scanner)
		if len(input) == 2 {
			heap.Insert(input[1])
		} else {
			fmt.Println(heap.Extract())
		}
	}
}

// Ищет первый индекс, где arr[i] >= target
func MinBinSearch(target int, arr []int) int {
	l, r := 0, len(arr)
	for l < r {
		mid := (l + r) / 2
		if arr[mid] < target {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}

// Ищет первый индекс, где arr[i] > target
func MaxBinSearch(target int, arr []int) int {
	l, r := 0, len(arr)
	for l < r {
		mid := (l + r) / 2
		if arr[mid] <= target {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}

func task5() []int {
	scanner := bufio.NewReader(os.Stdin)
	InputN(scanner)
	arr := InputNArray(scanner)
	sort.Ints(arr)
	m := InputN(scanner)
	var ans []int
	for i := 0; i < m; i++ {
		input := InputNArray(scanner)
		potentialLeftIdx, potentialRightIdx := MinBinSearch(input[0], arr), MaxBinSearch(input[1], arr)
		ans = append(ans, potentialRightIdx-potentialLeftIdx)
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return (-1) * x
	}
	return x
}

func MinModSearch(target int, arr []int) int {
	l, r := 0, len(arr)-1
	for {
		if r-l <= 1 {
			if abs(arr[l]-target) <= abs(arr[r]-target) {
				return l
			}
			return r
		}
		mid := l + (r-l)/2
		if arr[mid] <= target {
			l = mid
		} else {
			r = mid
		}
	}
}

func task6() []int {
	scanner := bufio.NewReader(os.Stdin)
	nLine, _ := scanner.ReadString('\n')
	nLine = strings.TrimSpace(nLine)
	arr := strings.Split(nLine, " ")
	m, _ := strconv.Atoi(arr[1])
	input := InputNArray(scanner)
	requests := InputNArray(scanner)
	var ans []int
	for i := 0; i < m; i++ {
		if requests[i] >= input[len(input)-1] {
			ans = append(ans, input[len(input)-1])
			continue
		} else if requests[i] <= input[0] {
			ans = append(ans, input[0])
			continue
		}
		ans = append(ans, input[MinModSearch(requests[i], input)])
	}
	return ans
}

func Min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func task7() int {
	scanner := bufio.NewReader(os.Stdin)
	arr := InputNArray(scanner)
	n, xSpeed, ySpeed := arr[0], arr[1], arr[2]
	if n == 1 {
		return Min(xSpeed, ySpeed)
	}
	l, r := 0, 2000000000
	for l < r {
		mid := l + (r-l)/2
		if n-1 <= ((mid / xSpeed) + (mid / ySpeed)) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l + Min(xSpeed, ySpeed)
}

func task8() int64 {
	scanner := bufio.NewReader(os.Stdin)
	arr := InputN64Array(scanner)
	var w, h, n, l, r int64 = arr[0], arr[1], arr[2], 0, 2*1e9 + 7
	for l < r {
		mid := l + (r-l)/2
		if (mid/w)*(mid/h) >= n {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func absFloat64(x float64) float64 {
	if x < 0 {
		return -x
	}
	return x
}

func f(x float64) float64 {
	return x*x + math.Sqrt(x)
}

func task9() float64 {
	var c float64
	fmt.Scanf("%f\n", &c)
	var l, r float64 = 0, 1e6
	for r-l > delta {
		mid := (l + r) / 2
		if f(mid) > c {
			r = mid
		} else {
			l = mid
		}
	}
	return l
}

func GetTime(x, y float64, vP, vF int) float64 {
	return (math.Sqrt(x*x+(1-y)*(1-y)) / float64(vP)) + (math.Sqrt((1-x)*(1-x)+y*y) / float64(vF))
}

// ternary search
func task10() float64 {
	scanner := bufio.NewReader(os.Stdin)
	input := InputNArray(scanner)
	vP, vF := input[0], input[1]
	str, _ := scanner.ReadString('\n')
	str = strings.TrimSpace(str)
	y, _ := strconv.ParseFloat(str, 64)
	l, r := 0.0, 1.0
	for r-l > delta {
		x1, x2 := (2*l+r)/3, (l+2*r)/3
		if GetTime(x1, y, vP, vF) <= GetTime(x2, y, vP, vF) {
			r = x2
		} else {
			l = x1
		}
	}
	return l
}

type Item struct {
	score float64
	index int
}

func task11() ([]Item, int) {
	scanner := bufio.NewReader(os.Stdin)
	arr := InputNArray(scanner)
	n, k := arr[0], arr[1]
	v, w := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		input := InputNArray(scanner)
		v[i], w[i] = input[0], input[1]
	}
	l, r := 0.0, M
	metricsArr := make([]float64, n)
	for r-l > delta {
		mid := l + (r-l)/2
		for i := 0; i < n; i++ {
			metricsArr[i] = float64(v[i]) - mid*float64(w[i])
		}
		sort.Slice(metricsArr, func(i, j int) bool {
			return metricsArr[i] > metricsArr[j]
		})

		sum := 0.0
		for i := 0; i < k; i++ {
			sum += metricsArr[i]
		}
		if sum < 0 {
			r = mid
		} else {
			l = mid
		}
	}

	items := make([]Item, n)
	for i := 0; i < n; i++ {
		items[i] = Item{
			score: float64(v[i]) - l*float64(w[i]),
			index: i,
		}
	}

	sort.Slice(items, func(i, j int) bool {
		if items[i].score == items[j].score {
			return items[i].index < items[j].index
		}
		return items[i].score > items[j].score
	})

	return items, k
}

func main() {
	ans, k := task11()
	for i := 0; i < k; i++ {
		fmt.Println(ans[i].index + 1)
	}
}
