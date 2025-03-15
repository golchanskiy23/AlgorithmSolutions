package main

import (
    "bufio"
    "fmt"
    "sort"
    "os"
)

func dfs(v int, matrix [][]int, visited []bool, ans []int) []int {
    visited[v] = true
    ans = append(ans, v)
    for u := 1; u < len(matrix[v]); u++ {
        if !visited[u] && matrix[v][u] == 1 {
            ans = dfs(u, matrix, visited, ans)
        }
    }
    return ans
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n, m int
    fmt.Fscan(reader, &n, &m)

    matrix := make([][]int, n+1)
    for i := 1; i <= n; i++ {
        matrix[i] = make([]int, n+1)
    }

    visited := make([]bool, n+1)
    ans := make([]int, 0)

    for i := 0; i < m; i++ {
        var f, s int
        fmt.Fscan(reader, &f, &s)
        matrix[f][s] = 1
        matrix[s][f] = 1
    }

    ans = dfs(1, matrix, visited, ans)
    sort.Ints(ans)
    fmt.Fprintln(writer, len(ans))
    for _, val := range ans {
        fmt.Fprintf(writer, "%d ", val)
    }
}