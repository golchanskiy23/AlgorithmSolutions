func searchMatrix(matrix [][]int, target int) bool {
    n,m := len(matrix), len(matrix[0])
    if matrix[0][0] > target || matrix[n-1][m-1] < target{
        return false
    }

    l,r := 0,n-1
    for l != r{
        mid := l+(r-l)/2
        if matrix[mid][m-1] < target{
            l = mid+1
        } else if matrix[mid][m-1] == target{
            return true
        } else{
            r = mid
        }
    }
    fmt.Println(l,r)

    r,t := 0,m-1
    for t - r >= 1{
        mid := r+(t-r)/2
        if matrix[l][mid] == target{
            return true
        } else if matrix[l][mid] > target{
            t = mid-1
        } else{
            r = mid+1
        }
    }
    fmt.Println(l,r,t)
    if matrix[l][r] != target{
        return false
    }
    return true
}