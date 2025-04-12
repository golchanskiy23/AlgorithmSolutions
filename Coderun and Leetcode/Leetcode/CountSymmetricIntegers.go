func isCorrect(i int) bool{
    s := strconv.Itoa(i)
    if len(s)%2 != 0{return false}
    lsum , rsum, l, r := 0,0, 0, len(s)-1
    for l < r{
        lsum += int(s[l]-'0')
        rsum += int(s[r]-'0')
        l++
        r--
    }
    return lsum == rsum
}

func countSymmetricIntegers(low int, high int) int {
    count := 0
    for i := low ; i <= high; i++{
        if isCorrect(i){count++}
    }

    return count
}