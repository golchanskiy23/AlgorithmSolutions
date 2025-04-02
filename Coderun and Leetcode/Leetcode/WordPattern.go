func wordPattern(pattern string, s string) bool {
    cs, sc := make(map[rune]string) , make(map[string]rune)
    arr := strings.Split(s, " ")
    if len(pattern) != len(arr){
        return false
    }
    b := []rune(pattern)
    for i := 0; i < len(b); i++{
        if val, ok := cs[b[i]]; ok == true {
            if val != arr[i] {
                fmt.Print(i)
                return false
            } 
        }
        if val , ok := sc[arr[i]]; ok == true {
            if val != b[i]{
                fmt.Print(i)
                return false
            }
        }
        cs[b[i]] = arr[i]
        sc[arr[i]] = b[i]
    }
    return true
}