func findSubstring(s string, words []string) []int {
    // закидываем words в map
    // создаём копию мапы , проходимся по каждому индексу s
    // прыгая на words[0].size() ищем строку в мапе

    ans, map_ := make([]int,0), make(map[string]int)
    for _, val := range words{
        map_[val]++
    }

    for i := 0; i <= len(s)-len(words[0])*len(words); i++{
        j, flag := i, false
        tmp := make(map[string]int)
        for k, v := range map_ {
            tmp[k] = v
        }
        for j < i+len(words[0])*len(words){
            substr := s[j:j+len(words[0])]
            if _ , ok := tmp[substr]; ok{
                tmp[substr]--
                if tmp[substr] == 0{
                    delete(tmp, substr)
                }
                if len(tmp) == 0{
                    flag = true
                }
            } else{
                break
            }
            j += len(words[0])
        }
        if flag{
            ans = append(ans, i)
        }
    }
    return ans
}