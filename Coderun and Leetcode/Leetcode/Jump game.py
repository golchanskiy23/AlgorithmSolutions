class Solution:
    def canJump(self, nums: List[int]) -> bool:
        flag = True
        i, defensed = 0, 0
        while i < len(nums):
            if defensed > 0:
                defensed -= 1
            if i+nums[i] >= len(nums)-1:
                break
            elif nums[i] == 0 and defensed == 0:
                flag = False
                break
            elif nums[i] > 0:
                if nums[i] > defensed:
                    defensed = nums[i]
                i += 1
            elif nums[i+nums[i]] == 0:
                i += 1
        return flag