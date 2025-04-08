type Pair struct{
    a,b int
}

func intersection(arr1, arr2 []int) bool{
    if arr1[1] >= arr2[0]{return true}
    return false
}

func findMinArrowShots(points [][]int) int {
    cnt, n := make([]Pair,0), len(points)
    sort.Slice(points, func(i,j int) bool{
        if points[i][1] == points[j][1] {return points[i][0] < points[j][0]}
        return points[i][1] < points[j][1]
    })

    i := 0
    for i < n{
        j := i
        for ; j < n; j++{
            if (intersection(points[i], points[j])) {
                if len(cnt) == 0{
                   cnt = append(cnt, Pair{a:i, b:j,}) 
                } else{
                    if cnt[len(cnt)-1].a != i && cnt[len(cnt)-1].b != j{
                        cnt = append(cnt, Pair{a:i, b:j,}) 
                    }
                }
            } else{
                break
            }
        }
        i = j
    }
    return len(cnt)
}