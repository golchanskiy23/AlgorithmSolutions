func canConstruct(ransomNote string, magazine string) bool {
    if len(magazine) < len(ransomNote){
        return false
    }

    fmap, smap := make(map[rune]int, 0), make(map[rune]int, 0) 
    fslice, sslice := []rune(magazine), []rune(ransomNote)
    for _, val := range fslice{
        fmap[val]++
    }
    
    for _, val := range sslice{
        smap[val]++
    }

    for _, val := range sslice{
        if fmap[val] < smap[val]{
            return false
        }
    }
    return true
}