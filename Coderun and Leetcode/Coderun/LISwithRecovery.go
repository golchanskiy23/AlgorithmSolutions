package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

func main() {
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

	//fmt.Println("LIS Length:", maxSeq)
	//fmt.Println("Array:", arr)
	//fmt.Println("DP:", dp)
	//fmt.Println("Indexes:", idxs)

	var lis []int
	for maxIdx != -1 {
		lis = append(lis, arr[maxIdx])
		maxIdx = idxs[maxIdx]
	}

	for i := len(lis) - 1; i >= 0; i-- {
		fmt.Print(lis[i], " ")
	}
	fmt.Println()
}