class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        ans, mx, last = 0,0, 0
        for i in range(0,len(nums)-1):
            mx = max(mx, i+nums[i])
            if i == last:
                ans += 1
                last = mx
        return ans