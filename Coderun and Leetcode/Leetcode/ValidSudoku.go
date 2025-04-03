func squareIdx(row, col int) int{
    if row == 0 || row == 1 || row == 2{
        if col <= 2{
            return 0
        } else if col <= 5{
            return 1
        } else {return 2}
    } else if row == 3 || row == 4 || row == 5{
        if col <= 2{
            return 3
        } else if col <= 5{
            return 4
        } else {return 5}
    } else{
        if col <= 2{
            return 6
        } else if col <= 5{
            return 7
        } else {return 8}
    }
}

func isValidSudoku(board [][]byte) bool {
    vectorOfSetsRows := make([]map[int]bool, 9)
    vectorOfSetsCols := make([]map[int]bool, 9)
    vectorOfSetsSquares := make([]map[int]bool, 9)

    for i:=0; i < 9; i++{
        vectorOfSetsRows[i] = make(map[int]bool)
        vectorOfSetsCols[i] = make(map[int]bool)
        vectorOfSetsSquares[i] = make(map[int]bool)
    }
    
    for i := 0; i < len(board); i++{
        for j := 0; j < len(board[i]); j++{
            if board[i][j] == 46 {continue}
            curr := int(board[i][j]-48)
            fmt.Println(curr, squareIdx(i,j)-1)
            if _, ok := vectorOfSetsRows[i][curr] ; ok == true{
                fmt.Println(i,j, curr)
                return false
            } else{
                 vectorOfSetsRows[i][curr] = true
            }

            if _, ok := vectorOfSetsCols[j][curr] ; ok == true{
                fmt.Println(i,j)
                return false
            } else{
                 vectorOfSetsCols[j][curr] = true
            }

            if _,ok := vectorOfSetsSquares[squareIdx(i,j)][curr]; ok == true{
                fmt.Println(i,j)
                 return false
            } else{
                 vectorOfSetsSquares[squareIdx(i,j)][curr] = true
            }
            
        }
    }

    return true
}