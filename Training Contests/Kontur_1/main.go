package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	dirX = []int{0, -1, 0, 1}
	dirY = []int{-1, 0, 1, 0}
)

func taskA(r *bufio.Reader) (int, string) {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	globalMax, maxString := 0, ""
	for i := 0; i < n; i++ {

		str, _ := r.ReadString('\n')
		str = strings.TrimSpace(str)
		strRune := []rune(str)

		set := make(map[rune]bool)
		for _, v := range strRune {
			set[v] = true
		}
		if len(set) > globalMax {
			globalMax = len(set)
			maxString = str
		}
	}
	return globalMax, maxString
}

func BHelper(r *bufio.Reader, n int) (int, int) {
	minX, minY, currX, currY := math.MaxInt, math.MaxInt, 0, 0
	for i := 0; i < n; i++ {
		str, _ := r.ReadString('\n')
		str = strings.TrimSpace(str)
		byteArr := strings.Split(str, " ")
		currX, _ = strconv.Atoi(byteArr[0])
		currY, _ = strconv.Atoi(byteArr[1])
		if currX < minX {
			minX = currX
			minY = currY
		} else if currX == minX && currY < minY {
			minY = currY
		}
	}
	return minX, minY
}

func taskB(r *bufio.Reader) (int, int) {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	firstMinX, firstMinY := BHelper(r, n)
	secondMaxX, secondMaxY := BHelper(r, n)
	return secondMaxX - firstMinX, secondMaxY - firstMinY
}

func taskB_througthBytes() {

}

func CIncreaseOrder(tmp []int, k, q int) int {
	sort.Ints(tmp)
	i, cnt := 0, 0
	for i < len(tmp) && tmp[i] < k {
		i++
		cnt++
	}
	for i < len(tmp) && q > 0 {
		i++
		cnt++
		q--
	}
	return cnt
}

func CDecreaseOrder(tmp []int, k, q int) int {
	sort.SliceStable(tmp, func(i, j int) bool {
		return tmp[i] >= tmp[j]
	})
	i, cnt := len(tmp)-1, 0
	for i >= 0 && q > 0 {
		i--
		cnt++
		q--
	}
	for i >= 0 {
		if tmp[i] < k {
			cnt++
		}
		i--
	}
	return cnt
}

func Max(x, y int) int {
	if x >= y {
		return x
	}
	return y
}

func taskC(r *bufio.Reader) int {
	var n, m, k int
	fmt.Fscanf(r, "%d %d %d\n", &n, &m, &k)
	str, _ := r.ReadString('\n')
	str = strings.TrimSpace(str)
	strs := strings.Split(str, " ")
	arr := make([]int, n)
	for i := 0; i < len(strs); i++ {
		arr[i], _ = strconv.Atoi(strs[i])
	}
	return Max(CIncreaseOrder(arr, m, k), CDecreaseOrder(arr, m, k))
}

func GetRegion(x []int, target int) int {
	n := int(len(x))
	i, j := int(0), n
	for i < j {
		h := i + (j-i)/2
		if x[h] < target {
			i = h + 1
		} else {
			j = h
		}
	}
	return i
}

func toInt(str string) int {
	var n int = 0
	for _, v := range str {
		n = n*10 + int(v-'0')
	}
	return n
}

func ReadArray(r *bufio.Reader) []int {
	str, _ := r.ReadString('\n')
	str = strings.TrimSpace(str)
	strs := strings.Split(str, " ")
	arr := make([]int, len(strs))
	for i := 0; i < len(strs); i++ {
		arr[i] = toInt(strs[i])
	}
	return arr
}

func taskD(r *bufio.Reader) {
	var n, m, u, v, q, x1, x2, y1, y2 int
	fmt.Fscanf(r, "%d %d\n", &n, &m)
	fmt.Fscanf(r, "%d %d\n", &u, &v)
	arrX, arrY := ReadArray(r), ReadArray(r)
	sort.Ints(arrX)
	sort.Ints(arrY)

	fmt.Fscanf(r, "%d\n", &q)
	for i := 0; i < q; i++ {
		fmt.Fscanf(r, "%d %d %d %d\n", &x1, &y1, &x2, &y2)
		rx_1 := GetRegion(arrX, x1)
		ry_1 := GetRegion(arrY, y1)

		rx_2 := GetRegion(arrX, x2)
		ry_2 := GetRegion(arrY, y2)

		if rx_1 == rx_2 && ry_1 == ry_2 {
			fmt.Println("YES\n")
		} else {
			fmt.Println("NO\n")
		}
	}
}

func dfs(matrix []int, m, n, x, y, shipIdx int) int {
	if x < 0 || x >= n || y < 0 || y >= m {
		return 0
	}

	idx := y*n + x

	if matrix[idx] != -1 {
		return 0
	}

	matrix[idx] = shipIdx
	ans := 0
	for i := 0; i < 4; i++ {
		ans += dfs(matrix, m, n, x+dirX[i], y+dirY[i], shipIdx)
	}

	return ans + 1
}

func taskE(r *bufio.Reader) {
	var n, m, q int
	fmt.Fscanf(r, "%d %d %d\n", &n, &m, &q)
	// idx = i*n+j
	matrix := make([]int, m*n)
	for i := range n {
		str, _ := r.ReadString('\n')
		str = strings.TrimSpace(str)
		strByte := []rune(str)
		for j, char := range strByte {
			if char == '.' {
				matrix[i*n+j] = 0
			} else {
				matrix[i*n+j] = -1
			}
		}
	}

	ships := make([]int, 0)
	for y := range m {
		for x := range n {
			if matrix[y*n+x] == -1 {
				shipIdx := len(ships) + 1
				ships = append(ships, dfs(matrix, m, n, x, y, shipIdx))
			}
		}
	}

	for i := 0; i < len(matrix); i++ {
		fmt.Print(matrix[i], " ")
		if (i+1)%m == 0 {
			fmt.Println()
		}
	}

	for _ = range q {
		str, _ := r.ReadString('\n')
		strs := strings.Split(str, " ")
		y, _ := strconv.Atoi(strs[0])
		x, _ := strconv.Atoi(strs[1])
		x -= 1
		y -= 1
		idx := y*n + x
		if matrix[idx] != 0 {
			ships[matrix[idx]-1] -= 1
			ship := ships[matrix[idx]-1]
			matrix[idx] = 0

			if ship == 0 {
				fmt.Printf("DESTROY\n")
			} else {
				fmt.Printf("HIT\n")
			}
		} else {
			fmt.Printf("MISS\n")
		}
	}

}

func main() {
	scanner := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	taskE(scanner)
}
