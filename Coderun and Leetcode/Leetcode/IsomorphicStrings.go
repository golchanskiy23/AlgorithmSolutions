func isValid(sRune, tRune []rune) bool{
    m := make(map[rune]rune)
    for i := 0; i < len(sRune); i++{
        if _, ok := m[sRune[i]]; ok == false{
                m[sRune[i]] = tRune[i]
        } else{
            if m[sRune[i]] != tRune[i] {
                return false
            }
        }
    }
    return true
}

func isIsomorphic(s string, t string) bool {
    sRune, tRune := []rune(s) , []rune(t)
    if len(sRune) != len(tRune){
        return false
    }
    return isValid(sRune, tRune) && isValid(tRune, sRune)
}