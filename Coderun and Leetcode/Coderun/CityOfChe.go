package main

import (
    "bufio"
    "fmt"
    "strings"
    "os"
    "strconv"
)

func main() {
    scanner := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n, m int
    fmt.Fscanf(scanner, "%d %d\n", &n, &m)
    t, _ := scanner.ReadString('\n')
    s := strings.TrimSpace(t)
    arr := strings.Split(s, " ")
    
    var a []int
    for _, str := range arr{
        num, _ := strconv.Atoi(str)
        a = append(a, num)
    }
    l,r, cnt := 0,0, 0
    for r < n{
        for r < n && a[r]-a[l] <= m{
            r++
        }
        cnt += n-r
        l++
    }
    
    fmt.Fprint(writer, cnt)
}