func wordBreak(s string, wordDict []string) bool {
    set := make(map[string]bool)
    for i := 0; i < len(wordDict); i++{
        set[wordDict[i]] = true
    }

    boolean := make([]bool, len(s)+1)
    boolean[0] = true
    for i := 1; i <= len(s); i++{
        for j := 0; j < i; j++{
            if _, ok := set[s[j:i]]; ok {
                    if boolean[j]{
                        boolean[i] = true;
                        // Break because we found a valid segmentation until i.
                        break;
                    }
                }
        }
    }
    return boolean[len(s)]
}