var(
    MOD int64 = 1000000007
)

func pow(a,b, MOD int64) int64{
    res := int64(1)
        for b > 0 {
            if b%2 == 1 {
                res = (res * a) % MOD
            }
            a = (a * a) % MOD
            b /= 2
        }
        return res
}

// 0,2,4,6,8 / 2,3,5,7
func countGoodNumbers(n int64) int {
    if n == 1{return 5}
    var evenCount int64 = n/2
    var oddCount int64 = (n+1)/2
    odd , even := pow(4,evenCount, MOD), pow(5, oddCount, MOD)
    return int((odd*even)%MOD)
}