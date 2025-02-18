class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix,suffix = [0]*(n+1), [0]*(n+1)
        prefix[0],suffix[0] = 1,1
        for i in range(0,n):
            prefix[i+1] = prefix[i]*nums[i]
            suffix[i+1] = suffix[i]*nums[n-i-1]
        ans = [0]*(n)
        for i in range(0,n):
            ans[i] = prefix[i]*suffix[n-1-i]
        return ans