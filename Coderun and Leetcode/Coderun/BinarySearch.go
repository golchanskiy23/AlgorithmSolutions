package main

import (
    "fmt"
    "bufio"
    "os"
)

func bSearch(arr []int, target int) string{
    l,r := 0, len(arr)-1
    for l < r{
        mid := l+(r-l)/2
        if arr[mid] == target{
            return "YES"
        } else if arr[mid] < target{
            l = mid+1
        } else{
            r = mid-1
        }
    }
    if arr[l] == target && l == r{
        return "YES"
    }
    return "NO"
}

func main() {
    var n,k,c int
    scanner := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()
    fmt.Fscan(scanner, &n,&k)

    arr1 := make([]int, n)
    for i:=0; i < n; i++{
        fmt.Fscan(scanner, &c)
        arr1[i] = c
    }

    for i:=0; i < k; i++{
        fmt.Fscan(scanner, &c)
        fmt.Fprintln(writer, bSearch(arr1, c))
    }

}