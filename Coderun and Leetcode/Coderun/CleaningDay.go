package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func main() {
    scanner := bufio.NewReader(os.Stdin)
    var n,r,c, tmp int
    fmt.Fscanf(scanner, "%d %d %d\n", &n, &r, &c)
    arr := make([]int, n)
    for i := 0; i < n; i++{
        fmt.Fscan(scanner, &tmp)
        arr[i] = tmp
    }
    sort.Ints(arr)
    left, right := 0, arr[len(arr)-1]-arr[0]
    for left < right {
        mid := left + (right-left)/2
        j,k :=0,0
        for j+c-1 < len(arr){
            if arr[j+c-1] - arr[j] <= mid{
                k++
                j += c
            } else{
                j++
            }
        }
        if k >= r{
            right = mid;
        } else{
            left = mid+1
        }
    }
    fmt.Print(right)
}