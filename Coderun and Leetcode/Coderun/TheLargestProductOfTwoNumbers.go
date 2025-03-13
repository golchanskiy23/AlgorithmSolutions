package main

import (
	"fmt"
	"sort"
	"os"
	"bufio"
    "strings"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	strNumbers := strings.Split(input, " ")

	var a []int
	for _, str := range strNumbers {
		num, err := strconv.Atoi(str)
		if err != nil {
			fmt.Println("Ошибка при преобразовании строки в число:", err)
			return
		}
		a = append(a, num)
	}

	sort.Ints(a)

	if a[0]*a[1] >= a[len(a)-1]*a[len(a)-2] {
		fmt.Fprintf(writer,"%d %d\n", a[0], a[1])
	} else {
		fmt.Fprintf(writer,"%d %d\n", a[len(a)-2], a[len(a)-1])
	}
}
