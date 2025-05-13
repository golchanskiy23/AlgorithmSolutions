func countAndSay(n int) string {
    str, idx := "1", 1
    for idx != n{
        bytesArr, c := strings.Split(str, ""), 1
        ans := make([]string, 0)
        fmt.Println(bytesArr)
        for i := 1; i < len(bytesArr); i++{
            if bytesArr[i] == bytesArr[i-1]{
                c++
            } else{
                repeats := strconv.Itoa(c)
                num := bytesArr[i-1]
                ans = append(ans, repeats, num)
                c = 1
            }
        }
        repeats := strconv.Itoa(c)
        num := bytesArr[len(bytesArr)-1]
        ans = append(ans, repeats, num)
        str = strings.Join(ans, "")
        fmt.Println(str)
        idx++
    }
    return str
}