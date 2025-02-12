class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [0]*(len(prices)-1)
        i,j=0,1
        while j < len(prices):
            dp[i] = prices[j]-prices[j-1]
            i += 1
            j += 1
        print(dp)
        curr = -1
        for i in range(len(dp)):
            if dp[i] < 0:
                continue
            else:
                curr = 0
                break
        if curr == -1:
            return 0
        ans = 0
        while i < len(dp):
            if dp[i] < 0:
                ans += curr
                curr = 0
                i += 1
                continue
            curr += dp[i]
            i += 1
        ans += curr
        return ans