func spiralOrder(matrix [][]int) []int {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return nil
    }

    top, bottom := 0, len(matrix)-1
    left, right := 0, len(matrix[0])-1
    ans := make([]int, 0, (bottom+1)*(right+1))

    for top <= bottom && left <= right {
        for j := left; j <= right; j++ {
            ans = append(ans, matrix[top][j])
        }
        top++
        for i := top; i <= bottom; i++ {
            ans = append(ans, matrix[i][right])
        }
        right--
        if top <= bottom {
            for j := right; j >= left; j-- {
                ans = append(ans, matrix[bottom][j])
            }
            bottom--
        }
        if left <= right {
            for i := bottom; i >= top; i-- {
                ans = append(ans, matrix[i][left])
            }
            left++
        }
    }

    return ans
}