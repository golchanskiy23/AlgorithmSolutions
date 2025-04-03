package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const INT = 100000

func taskA(r *bufio.Reader) int {
	var a, b int
	fmt.Fscanf(r, "%d %d\n", &a, &b)
	if a == 0 || b == 0 {
		if a == 0 && b != 0 {
			return 2
		} else if a != 0 && b == 0 {
			return 1
		}
		return 0
	}
	if a < b {
		return 2*(a+1) + a
	} else if a == b {
		return 3 * a
	}
	return 2*(b) + (b + 1)
}

func taskB(reader *bufio.Reader) string {
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	strs := strings.Split(str, " ")
	arr := make([]int, n)
	for i := range arr {
		arr[i], _ = strconv.Atoi(strs[i])
	}

	l, r, lsum, rsum := 0, n-1, arr[0], arr[n-1]
	flag := false
	for r-l >= 1 {
		if lsum < rsum {
			l++
			lsum += arr[l]
		} else if lsum > rsum {
			r--
			rsum += arr[r]
		} else {
			if r-l == 1 {
				flag = true
				break
			} else {
				l++
				r--
				lsum += arr[l]
				rsum += arr[r]
			}
		}
	}
	if flag {
		s1 := strings.Trim(strings.Join(strings.Fields(fmt.Sprint(arr[0:l+1])), "+"), "[]")
		s2 := strings.Trim(strings.Join(strings.Fields(fmt.Sprint(arr[l+1:n])), "+"), "[]")
		return fmt.Sprintf("%s=%s", s1, s2)
	}
	return fmt.Sprintf("%d", -1)
}

type Point struct {
	val, timestamp int
}

func max(a, b Point) int {
	if a.timestamp > b.timestamp {
		return a.val
	}
	return b.val
}

func taskC(r *bufio.Reader) {
	colArr, rowArr := make([]Point, INT+1), make([]Point, INT+1)
	for i := 0; i < INT+1; i++ {
		colArr[i], rowArr[i] = Point{0, 0}, Point{0, 0}
	}
	var n, m, t, x, y, c int
	fmt.Fscanf(r, "%d %d\n", &n, &m)
	fmt.Fscanf(r, "%d\n", &t)
	for i := 0; i < t; i++ {
		str, _ := r.ReadString('\n')
		str = strings.TrimSpace(str)
		strs := strings.Split(str, " ")
		x, _ = strconv.Atoi(strs[0])
		y, _ = strconv.Atoi(strs[1])
		c, _ = strconv.Atoi(strs[2])
		rowArr[x-1] = Point{
			val:       c,
			timestamp: i + 1,
		}
		colArr[y-1] = Point{
			val:       c,
			timestamp: i + 1,
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if j == m-1 {
				fmt.Printf("%d", max(rowArr[i], colArr[j]))
				break
			}
			fmt.Printf("%d ", max(rowArr[i], colArr[j]))
		}
		fmt.Println()
	}
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func taskD(r *bufio.Reader) int {
	var n, k int
	fmt.Fscanf(r, "%d %d\n", &n, &k)
	str, _ := r.ReadString('\n')
	str = strings.TrimSpace(str)
	runeArr, staticArr := []rune(str), []rune("RGB")
	ans := 0
	for _, val := range staticArr {
		cur, l := 0, 0
		for j := 0; j < n; j++ {
			if val != runeArr[j] {
				cur++
			}
			for l < j && cur > k {
				if val != runeArr[l] {
					cur--
				}
				l++
			}
			ans = maxInt(ans, j-l+1)
		}
	}
	return ans
}

func main() {
	scanner := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fprint(writer, taskD(scanner))
}
