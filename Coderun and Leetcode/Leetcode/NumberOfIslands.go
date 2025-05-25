var (
    dirX = []int{0,-1,0,1}
    dirY = []int{-1,0,1,0}
)

func isValid(x,y,n,m int) bool{
    if x < 0 || y < 0 || y >= m || x >= n{
        return false
    }
    return true
}

func dfs(x,y,n,m int, visited [][]bool, grid [][]byte){
    visited[x][y] = true
    fmt.Println(x,y)
    for i := 0; i < 4; i++{
        currX, currY := x+dirX[i], y+dirY[i]
        if isValid(currX,currY,n,m) && !visited[currX][currY] && grid[currX][currY] == '1'{
            dfs(currX, currY,n,m, visited,grid)
        }
    }
}

func numIslands(grid [][]byte) int {
    n, m := len(grid), len(grid[0])
    numOfIslands := 0
    visited := make([][]bool, n)
    for i := 0; i < n; i++{
        visited[i] = make([]bool, m)
    }

    for i := 0; i < n; i++{
        for j := 0; j < m; j++{
            if !visited[i][j] && grid[i][j] == '1'{
                dfs(i,j, n,m,visited,grid)
                numOfIslands += 1
            }
        }
    }
    return numOfIslands
}