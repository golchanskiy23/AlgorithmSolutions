func reverseWords(s string) string {
    t := strings.TrimSpace(s)
    l := 0
    var isString bool = false
    slice := make([]string,0)
    arr := []rune(t)
    for i, _ := range arr{
        val := arr[i]
        if unicode.IsLetter(val) || unicode.IsDigit(val){
            if !isString{
                l = i;
                isString = true
            }      
        } else {
            if isString == true{
                slice = append(slice, string(arr[l:i]))
                isString = false
            }
        }
    }

    slice = append(slice, string(arr[l:]))
    n := len(slice)

    for i,j:=0,n-1; i < j; i,j = i+1,j-1{
        slice[i], slice[j] = slice[j], slice[i]
    }

    return strings.Join(slice, " ")
}