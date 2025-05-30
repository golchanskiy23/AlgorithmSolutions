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

const MOD = 1e9

func InputNArray(scanner *bufio.Reader) []int {
	str, _ := scanner.ReadString('\n')
	str = strings.TrimSpace(str)
	nums := strings.Split(str, " ")
	arr := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		arr[i], _ = strconv.Atoi(nums[i])
	}
	return arr
}

func InputN(scanner *bufio.Reader) int {
	nLine, _ := scanner.ReadString('\n')
	nLine = strings.TrimSpace(nLine)
	n, _ := strconv.Atoi(nLine)
	return n
}

func task1() {
	scanner := bufio.NewReader(os.Stdin)
	params := InputNArray(scanner)
	n, k := params[0], params[1]

	str, _ := scanner.ReadString('\n')
	str = strings.TrimSpace(str)
	nums := strings.Split(str, " ")

	coins := make([]int, n)
	coins[0] = 0
	coins[n-1] = 0
	for i := 1; i < n-1; i++ {
		coins[i], _ = strconv.Atoi(nums[i-1])
	}

	deque := []int{0}
	dp := make([]int, n)
	parent := make([]int, n)
	dp[0], parent[0] = 0, -1

	for i := 1; i < n; i++ {
		for len(deque) > 0 && deque[0] < i-k {
			deque = deque[1:]
		}

		dp[i] = dp[deque[0]] + coins[i]
		parent[i] = deque[0]

		for len(deque) > 0 && dp[deque[len(deque)-1]] <= dp[i] {
			deque = deque[:len(deque)-1]
		}

		deque = append(deque, i)
	}

	fmt.Println(dp[n-1])

	path := []int{}
	cur := n - 1
	for cur != -1 {
		path = append(path, cur+1)
		cur = parent[cur]
	}

	for i, j := 0, len(path)-1; i < j; i, j = i+1, j-1 {
		path[i], path[j] = path[j], path[i]
	}

	fmt.Println(len(path) - 1)
	for _, x := range path {
		fmt.Printf("%d ", x)
	}
	fmt.Println()
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func task2() {
	scanner := bufio.NewReader(os.Stdin)
	arr := InputNArray(scanner)
	n, k := arr[0], arr[1]
	grid, dp := make([][]int, n), make([][]int, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]int, k)
		dp[i] = make([]int, k)
	}
	for i := 0; i < n; i++ {
		grid[i] = InputNArray(scanner)
	}
	dp[0][0] = grid[0][0]
	for i := 0; i < n; i++ {
		for j := 0; j < k; j++ {
			if i == 0 && j == 0 {
				continue
			}
			t, s := -math.MaxInt, -math.MaxInt
			if i > 0 {
				t = dp[i-1][j]
			}
			if j > 0 {
				s = dp[i][j-1]
			}
			dp[i][j] = Max(t, s) + grid[i][j]
		}
	}

	fmt.Println(dp[n-1][k-1])
	ans := make([]byte, 0)
	n_i, m_i := n-1, k-1
	for n_i != 0 || m_i != 0 {
		if n_i > 0 && dp[n_i][m_i] == grid[n_i][m_i]+dp[n_i-1][m_i] {
			ans = append(ans, 'D')
			n_i--
		} else {
			m_i--
			ans = append(ans, 'R')
		}
	}
	l, r := 0, len(ans)-1
	for l < r {
		ans[l], ans[r] = ans[r], ans[l]
		l++
		r--
	}
	for _, val := range ans {
		fmt.Printf("%c", val)
	}
}

func task3() {
	var n int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	strs := strings.Split(str, " ")

	arr := make([]int, n)
	dp := make([]int, n)
	idxs := make([]int, n)
	for i := range idxs {
		idxs[i] = -1
	}

	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strs[i])
	}

	for i := 0; i < n; i++ {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if arr[i] > arr[j] && dp[j]+1 > dp[i] {
				dp[i] = dp[j] + 1
				idxs[i] = j
			}
		}
	}

	maxIdx, maxSeq := 0, 0
	for i := 0; i < n; i++ {
		if dp[i] > maxSeq {
			maxSeq = dp[i]
			maxIdx = i
		}
	}

	var lis []int
	for maxIdx != -1 {
		lis = append(lis, arr[maxIdx])
		maxIdx = idxs[maxIdx]
	}

	fmt.Println(len(lis))
	for i := len(lis) - 1; i >= 0; i-- {
		fmt.Print(lis[i], " ")
	}
	fmt.Println()
}

func task4() int {
	scanner := bufio.NewReader(os.Stdin)
	n := InputN(scanner)
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, 10)
	}
	for j := 0; j < 10; j++ {
		if j != 0 && j != 8 {
			dp[1][j] = 1
		}
	}

	for i := 2; i <= n; i++ {
		for j := 0; j < 10; j++ {
			switch j {
			case 1:
				dp[i][j] = dp[i-1][8] + dp[i-1][6]
			case 2:
				dp[i][j] = dp[i-1][7] + dp[i-1][9]
			case 3:
				dp[i][j] = dp[i-1][4] + dp[i-1][8]
			case 4:
				dp[i][j] = (dp[i-1][0]+dp[i-1][9])%MOD + dp[i-1][3]
			case 5:
				dp[i][j] = 0
			case 6:
				dp[i][j] = (dp[i-1][1]+dp[i-1][7])%MOD + dp[i-1][0]
			case 7:
				dp[i][j] = dp[i-1][2] + dp[i-1][6]
			case 8:
				dp[i][j] = dp[i-1][1] + dp[i-1][3]
			case 9:
				dp[i][j] = dp[i-1][4] + dp[i-1][2]
			default:
				dp[i][j] = dp[i-1][4] + dp[i-1][6]
			}
			dp[i][j] %= MOD
		}
	}
	ans := 0
	for j := 0; j < 10; j++ {
		ans += dp[n][j]
		ans %= MOD
	}
	return ans
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func Min3(a, b, c int) int {
	return min(a, min(b, c))
}

func task5() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s1 := scanner.Text()
	scanner.Scan()
	s2 := scanner.Text()

	n, m := len(s1), len(s2)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}

	for i := 0; i <= n; i++ {
		dp[i][0] = i
	}
	for j := 0; j <= m; j++ {
		dp[0][j] = j
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			substitutionCost := 0
			if s1[i-1] != s2[j-1] {
				substitutionCost = 1
			}
			dp[i][j] = Min3(
				dp[i-1][j]+1,
				dp[i][j-1]+1,
				dp[i-1][j-1]+substitutionCost,
			)
		}
	}

	fmt.Println(dp[n][m])
}

func task6() {
	scanner := bufio.NewReader(os.Stdin)
	n := InputN(scanner)
	days := make([]int, n+1)
	for i := 1; i <= n; i++ {
		days[i] = InputN(scanner)
	}

	const INF = math.MaxInt32
	dp := make([][]int, n+1)
	prev := make([][]int, n+1)
	used := make([][]bool, n+1)

	for i := 0; i <= n; i++ {
		dp[i] = make([]int, n+1)
		prev[i] = make([]int, n+1)
		used[i] = make([]bool, n+1)
		for j := 0; j <= n; j++ {
			dp[i][j] = INF
			prev[i][j] = -1
		}
	}
	dp[0][0] = 0

	for i := 1; i <= n; i++ {
		for k := 0; k <= n; k++ {
			if k+1 <= n && dp[i-1][k+1] < dp[i][k] {
				dp[i][k] = dp[i-1][k+1]
				prev[i][k] = k + 1
				used[i][k] = true
			}
			addCoupon := 0
			if days[i] > 100 {
				addCoupon = 1
			}
			if k >= addCoupon && dp[i-1][k-addCoupon]+days[i] < dp[i][k] {
				dp[i][k] = dp[i-1][k-addCoupon] + days[i]
				prev[i][k] = k - addCoupon
				used[i][k] = false
			}
		}
	}

	ans, couponsLeft := INF, 0
	for k := 0; k <= n; k++ {
		if dp[n][k] < ans || (dp[n][k] == ans && k > couponsLeft) {
			ans = dp[n][k]
			couponsLeft = k
		}
	}

	fmt.Println(ans)

	usedDays := []int{}
	curK := couponsLeft
	for day := n; day >= 1; day-- {
		if used[day][curK] {
			usedDays = append(usedDays, day)
		}
		curK = prev[day][curK]
	}

	sort.Ints(usedDays)
	fmt.Printf("%d %d\n", couponsLeft, len(usedDays))
	for _, d := range usedDays {
		fmt.Println(d)
	}
}

func restore(i, j int, s []rune, pred [][]int) string {
	if i > j {
		return ""
	}
	if i == j {
		return ""
	}
	if pred[i][j] == -1 {
		return string(s[i]) + restore(i+1, j-1, s, pred) + string(s[j])
	}
	k := pred[i][j]
	return restore(i, k, s, pred) + restore(k+1, j, s, pred)
}

func task7() {
	scanner := bufio.NewReader(os.Stdin)
	str, _ := scanner.ReadString('\n')
	str = strings.TrimSpace(str)
	runes := []rune(str)
	dp, pred := make([][]int, len(runes)), make([][]int, len(runes))
	for i := range dp {
		dp[i] = make([]int, len(runes))
		pred[i] = make([]int, len(runes))
		dp[i][i] = 1
	}
	for length := 2; length <= len(runes); length++ {
		for i := 0; i < len(runes)-length+1; i++ {
			j := i + length - 1
			var curr int
			if (runes[i] == '{' && runes[j] == '}') ||
				(runes[i] == '(' && runes[j] == ')') ||
				(runes[i] == '[' && runes[j] == ']') {
				curr = dp[i+1][j-1]
			} else {
				curr = math.MaxInt
			}
			p := -1

			for k := i; k < j; k++ {
				if dp[i][k]+dp[k+1][j] < curr {
					p = k
					curr = dp[i][k] + dp[k+1][j]
				}
			}
			dp[i][j] = curr
			pred[i][j] = p
		}
	}

	fmt.Println(restore(0, len(dp[0])-1, runes, pred))
}

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	v, _ := strconv.Atoi(scanner.Text())
	return v
}

func readIntArray(scanner *bufio.Scanner, n int) []int {
	scanner.Scan()
	parts := strings.Fields(scanner.Text())
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(parts[i])
	}
	return arr
}

func task8() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	n := readInt(scanner)
	n++
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, n)
	}

	for i := 1; i < n; i++ {
		line := readIntArray(scanner, n)
		for j := 1; j < n; j++ {
			a[i][j] = line[j]
		}
	}

	INF := math.MaxInt32 / 2
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 1<<n)
		for j := 0; j < (1 << n); j++ {
			dp[i][j] = INF
		}
	}
	dp[0][0] = 0

	for mask := 0; mask < (1 << n); mask++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if (mask & (1 << j)) != 0 {
					prevMask := mask &^ (1 << j)
					if dp[j][prevMask] == INF {
						continue
					}
					dp[i][mask] = min(dp[i][mask], dp[j][prevMask]+a[i][j])
				}
			}
		}
	}

	fmt.Println(dp[0][(1<<n)-1])

	i := 0
	mask := (1 << n) - 1
	path := []int{}
	for mask > 0 {
		for j := 0; j < n; j++ {
			if (mask & (1 << j)) != 0 {
				prevMask := mask &^ (1 << j)
				if dp[i][mask] == dp[j][prevMask]+a[i][j] {
					if j != 0 {
						path = append(path, j)
					}
					i = j
					mask = prevMask
					break
				}
			}
		}
	}

	for k := len(path) - 1; k >= 0; k-- {
		fmt.Printf("%d ", path[k])
	}
	fmt.Println()
}

func main() {
	task8()
}
