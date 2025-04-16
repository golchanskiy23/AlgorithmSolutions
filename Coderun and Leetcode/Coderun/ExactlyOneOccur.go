package main

import (
    "bufio"
    "fmt"
    "strings"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n int
    fmt.Fscanf(reader, "%d\n", &n)
    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)
    strs := strings.Split(str, " ")
    m := make(map[int]int)
    for i := 0; i < n; i++{
        num, _ := strconv.Atoi(strs[i])
        m[num]++
    }
    ans := 0
    for _, val := range m{
        if val == 1{ans++}
    }
    fmt.Print(ans)
}