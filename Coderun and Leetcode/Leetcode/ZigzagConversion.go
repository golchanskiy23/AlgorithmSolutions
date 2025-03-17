func convert(s string, numRows int) string {
    if numRows == 1{
        return s
    }
    matrix := make([][]rune,numRows)
    for i:=0; i < numRows; i++{
        matrix[i] = make([]rune, 0)
    }
    t := []rune(s)
    row, direction := 0,-1
    for _ , val := range t{
        matrix[row] = append(matrix[row], val)
        if row == 0 || row == numRows-1{
            direction = direction*(-1)
        }
        row += direction
    }
    slice := make([]string, 0)
    for i:=0; i < numRows; i++{
        for j:=0; j < len(matrix[i]); j++{
                slice = append(slice, string(matrix[i][j]))
            }
    }
    return strings.Join(slice,"")
}