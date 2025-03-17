func strStr(haystack string, needle string) int {
    if len(needle) > len(haystack){
        return -1
    }
    if needle == haystack{
        return 0
    }
    for i:=0; i <= len(haystack)-len(needle);i++{
        if needle == haystack[i:i+len(needle)]{
            return i
        }
        fmt.Println(needle, haystack[i:i+len(needle)])
    }
    return -1
}