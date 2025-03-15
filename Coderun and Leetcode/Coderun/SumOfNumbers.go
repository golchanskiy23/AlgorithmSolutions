package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n,k,curr int
    fmt.Fscan(reader, &n, &k)

	var a []int
	for i := 0; i < n; i++ {
	    fmt.Fscan(reader, &curr)
		a = append(a, curr)
	}

    l,r := 0,0
    for r < n && a[r] > k{
        r++
    }

    currSum, ans := 0,0
    for r < n {
        currSum += a[r]
        for currSum > k && l <= r{
            currSum -= a[l]
            l++
        }
        if currSum == k{
            ans++
            r++
        }
        if currSum < k{
            r++
        }
    }
    fmt.Fprintln(writer, ans)
}