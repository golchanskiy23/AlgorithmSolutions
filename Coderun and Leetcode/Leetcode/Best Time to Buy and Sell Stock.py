class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #size == 1
        dp = [0]*(len(prices)-1)
        i,j=0,1
        while j < len(prices):
            dp[i] = prices[j]-prices[j-1]
            i += 1
            j += 1
        print(dp)
        max_, start= 0, -1
        for i in range(len(dp)):
            if dp[i] < 0:
                continue
            else:
                start = 0
                break
        if start == -1:
            return 0
        while i < len(dp):
            print(max_)
            start += dp[i]
            max_ = max(max_, start)
            if start < 0:
                start = 0
            i += 1
        return max_