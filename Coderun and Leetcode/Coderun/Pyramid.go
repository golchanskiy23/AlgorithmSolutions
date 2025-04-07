package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int
    fmt.Fscan(reader, &n)
    arr := make([]int, n)
    ma := make(map[int]int)
    for i := 0; i < n; i++{
        var l,m int
        fmt.Fscan(reader, &l, &m)
        if _, ok := ma[l]; ok == false {
            ma[l] = m
            arr = append(arr, l)
        } else{
            if m > ma[l] {ma[l] = m}
        }
    }
    sort.Slice(arr, func(i,j int) bool{
        return arr[i] > arr[j]
    })
    ans := 0
    for i:=0; i < len(ma); i++{
        ans += ma[arr[i]]
    }
    fmt.Fprint(writer, ans)
}