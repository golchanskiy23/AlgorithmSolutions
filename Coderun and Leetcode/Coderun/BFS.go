package main

import (
    "fmt"
)

type Queue struct {
    items []int
}

func (q *Queue) Push(item int) {
    q.items = append(q.items, item)
}

func (q *Queue) Pop() int {
    if len(q.items) == 0 {
        panic("Queue is empty")
    }

    item := q.items[0]
    q.items = q.items[1:]
    return item
}

func (q Queue) Front() int {
    if len(q.items) == 0 {
        panic("Queue is empty")
    }
    return q.items[0]
}

func (q Queue) IsEmpty() bool {
    return len(q.items) == 0
}

func bfs(graph [][]int, start int, end int, N int) int {
    visited := make([]bool,N)
    distance := make([]int,N)
    for i:=0; i < N; i++{
        distance[i] = -1
    }
    queue := &Queue{}
    visited[start] = true
    distance[start] = 0
    queue.Push(start)

    for !queue.IsEmpty(){
        var curr int = queue.Front()
        queue.Pop()

        if curr == end{
            return distance[curr]
        }
        for i:=0; i < N; i++{
            if graph[curr][i] == 1 && !visited[i]{
                visited[i] = true
                distance[i] = distance[curr]+1
                queue.Push(i)
            }
        }
    }
    return -1
}

func main() {
    var N int
    fmt.Scan(&N)
    graph := make([][]int, N)
    for i:=0; i < N; i++{
        graph[i] = make([]int, N)
    }
    for i:=0; i < N; i++{
        for j:=0; j < N; j++{
            var c int
            fmt.Scan(&c)
            graph[i][j] = c
        }
    }
    var start, end int
    fmt.Scan(&start, &end)
    start--
    end--

    ans := bfs(graph, start, end, N)
    fmt.Println(ans)
}