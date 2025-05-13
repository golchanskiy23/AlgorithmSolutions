package main

import (
    "bufio"
    "fmt"
    "strings"
    "strconv"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)
    strs := strings.Split(str, " ")
    arr := make([]int,len(strs))
    for i := 0; i < len(strs); i++{
        arr[i], _ = strconv.Atoi(strs[i])
    }
    if len(arr) == 0{
        fmt.Print("YES")
        return
    }

    curr := arr[0]
    for i := 1; i < len(arr); i++{
        if curr >= arr[i]{
            fmt.Print("NO")
            return
        }
        curr = arr[i]
    }
    fmt.Print("YES")
}