func isAnagram(s string, t string) bool {
    n,m := []byte(s), []byte(t)
    if len(n) != len(m){
        return false
    }
    sort.Slice(n, func(i,j int) bool{
        return n[i] < n[j]
    })
    sort.Slice(m, func(i,j int) bool{
        return m[i] < m[j]
    })
    for i := 0; i < len(n); i++{
        if n[i] != m[i]{
            return false
        }
    }
    return true
}