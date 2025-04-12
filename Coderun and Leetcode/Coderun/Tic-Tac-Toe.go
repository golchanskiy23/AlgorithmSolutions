package main

import (
    "bufio"
    "fmt"
    "strings"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n,m int
    fmt.Fscanf(reader, "%d %d\n", &n, &m)
    board := make([][]byte, n)
    for i:=0; i < n; i++{
        str , _ := reader.ReadString('\n')
        str = strings.TrimSpace(str)
        board[i] = []byte(str)
    }

    directions := [][2]int{
        {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1},
    }

    for i := 0; i < n; i++{
        for j := 0; j < m; j++{
            for _, d := range directions{
                if board[i][j] == '.'{
                    continue
                }

                count, nextX, nextY := 1, i+d[0], j+d[1]
                for count < 5 && nextX >= 0 && nextY >= 0 && nextX < n && nextY < m && board[nextX][nextY] == board[i][j]{
                    count++
                    nextX += d[0]
                    nextY += d[1]
                }

                if count == 5{
                    fmt.Println("Yes")
                    return
                }
            }
        }
        
    }
    fmt.Println("No")
}