package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var b, w int
    fmt.Fscanf(reader, "%d %d\n", &b, &w)

    f, s := (b + 4) / 2, b + w

    discriminant := float64(f*f - 4*s)

    sqrtD := math.Sqrt(discriminant)
    sol1 := (float64(f) + sqrtD) / 2
    sol2 := (float64(f) - sqrtD) / 2

    var width, height int
    if sol1 == float64(int(sol1)) && sol1 > 0 {
        width = int(sol1)
        height = f - width
    } else {
        width = int(sol2)
        height = f - width
    }

    fmt.Printf("%d %d\n", width, height)
}
