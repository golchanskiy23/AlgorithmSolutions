package main

import (
	"fmt"
    "os"
    "bufio"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var a int
    fmt.Fscan(reader, &a)
    m1 := make(map[string]string)
    for a > 0{
        var str1,str2 string
        fmt.Fscan(reader, &str1, &str2)
        m1[str1] = str2
        m1[str2] = str1
        a--        
    }

    var str string
    fmt.Fscan(reader, &str)
    if value, ok := m1[str]; ok{
        fmt.Fprintln(writer, value)
    }
}