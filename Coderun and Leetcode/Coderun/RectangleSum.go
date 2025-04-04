package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	//fmt.Fprint(writer, taskA(reader))
	defer writer.Flush()
	var n, m, k int
	fmt.Fscanf(reader, "%d %d %d\n", &n, &m, &k)

	prefix := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		prefix[i] = make([]int, m+1)
	}

	for i := 1; i <= n; i++ {
		str, _ := reader.ReadString('\n')
		str = strings.TrimSpace(str)
		strs := strings.Split(str, " ")
		for j := 1; j <= len(strs); j++ {
			num, _ := strconv.Atoi(strs[j-1])
			prefix[i][j] = num
		}
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			prefix[i][j] += prefix[i-1][j] + prefix[i][j-1]
			prefix[i][j] -= prefix[i-1][j-1]
		}
	}

	for i := 0; i < k; i++ {
		str, _ := reader.ReadString('\n')
		str = strings.TrimSpace(str)
		strs := strings.Split(str, " ")
		x1, _ := strconv.Atoi(strs[0])
		y1, _ := strconv.Atoi(strs[1])
		x2, _ := strconv.Atoi(strs[2])
		y2, _ := strconv.Atoi(strs[3])
		fmt.Fprintln(writer, prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1])
	}

}