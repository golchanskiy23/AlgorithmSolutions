package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
    "sort"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n,m, a, b int
    fmt.Scan(&n,&m)

    arr := make([][]int, m)
    for i := 0; i < m; i++{
        str , _ := reader.ReadString('\n')
        str = strings.TrimSpace(str)
        strs := strings.Split(str, " ")
        a, _ = strconv.Atoi(strs[0])
        b, _ = strconv.Atoi(strs[1])
        currArr := []int{a,b}
        arr[i] = currArr
    }

    sort.Slice(arr, func(i,j int) bool{
        if arr[i][0] == arr[j][0]{
            return arr[i][1] < arr[j][1]
        }
        return arr[i][0] < arr[j][0]
    })

    start, end := arr[0][0], arr[0][1]
        var ans [][]int
        for i := 1; i < len(arr); i++{
            if arr[i][0] <= end {
                if arr[i][1] > end {end = arr[i][1]}
            } else{
                ans = append(ans, []int{start, end})
                start = arr[i][0]
                end = arr[i][1]
            }
        }
        if len(ans) == 0 || ans[len(ans)-1][1] != arr[len(arr)-1][1] {
            ans = append(ans, []int{start, end})
        }

    for i:= 0;i < len(ans); i++{
        n -= (ans[i][1]-ans[i][0]+1)
    }
    fmt.Println(n)
}