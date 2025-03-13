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
	var str string

	fmt.Fscan(reader, &n)

	vectorOfSets := make([]map[string]bool, n)
	globalSet := make(map[string]bool)

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &m)
		vectorOfSets[i] = make(map[string]bool)
		for j := 0; j < m; j++ {
			fmt.Fscan(reader, &str)
			vectorOfSets[i][str] = true
			globalSet[str] = true
		}
	}

	currSet := vectorOfSets[0]
	for i := 1; i < n; i++ {
		tmp := make(map[string]bool)
		for key := range currSet {
			if vectorOfSets[i][key] {
				tmp[key] = true
			}
		}
		currSet = tmp
	}
	fmt.Fprintln(writer, len(currSet))
	for key := range currSet {
		fmt.Fprintln(writer, key)
	}

	fmt.Fprintln(writer, len(globalSet))
	for key := range globalSet {
		fmt.Fprintln(writer, key)
	}
}