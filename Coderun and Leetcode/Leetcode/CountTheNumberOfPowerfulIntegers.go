var(
    currString = ""
    suffix = ""
    digitsLim int = 0
    memo       [20][2]int64
	visited    [20][2]bool
)

func dfs(pos int, isLimit bool) int64{
    if len(currString) < len(suffix) {return 0}
    if pos + len(suffix) == len(currString){
        if isLimit{
            numSuffix, _ := strconv.ParseInt(suffix, 10, 64)
            numCurrString, _ := strconv.ParseInt(currString[pos:], 10, 64)
            if numSuffix <= numCurrString{
                return 1
            } else{
                return 0
            }
        }
        return 1
    }
    var upperBound int
    if isLimit{
        upperBound = int(currString[pos]-'0')
    } else{
        upperBound = 9
    }

    upperBound = min(upperBound , digitsLim)
    key := 0
	if isLimit {
		key = 1
	}
	if visited[pos][key] {
		return memo[pos][key]
	}

    var count int64 = 0
    for i := 0; i <= upperBound; i++{
        count += dfs(pos+1, isLimit && i == int(currString[pos]-'0'))
    }

    visited[pos][key] = true
	memo[pos][key] = count
	return count
}

func countPowerful(num int64) int64{
    currString = strconv.FormatInt(num, 10)
    for i := range memo {
		for j := range memo[i] {
			memo[i][j] = 0
			visited[i][j] = false
		}
	}
    return dfs(0,true)
}

func numberOfPowerfulInt(start int64, finish int64, limit int, s string) int64 {
    suffix, digitsLim = s , limit
    first := countPowerful(start-1)
    for i := range memo {
		for j := range memo[i] {
			fmt.Print(memo[i][j], " ")
		}
        fmt.Println()
	}
    second := countPowerful(finish)
    return second-first
}