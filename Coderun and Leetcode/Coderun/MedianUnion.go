package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int
	fmt.Fscan(reader, &n, &m)

	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(reader, &matrix[i][j])
		}
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			lstart, rstart, target := 0, 0, (2*m-1)/2
			var median int

			for k := 0; k <= target; k++ {
				if lstart < m && (rstart >= m || matrix[i][lstart] <= matrix[j][rstart]) {
					median = matrix[i][lstart]
					lstart++
				} else {
					median = matrix[j][rstart]
					rstart++
				}
			}

			fmt.Fprintln(writer, median)
		}
	}
}