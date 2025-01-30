class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        curr_idx = 1
        
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[curr_idx] = nums[i]
                curr_idx += 1
        
        return curr_idx