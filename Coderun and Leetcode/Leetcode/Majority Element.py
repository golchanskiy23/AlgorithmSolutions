class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        m = {}
        for i in range(0, len(nums)):
            if nums[i] not in m:
                m[nums[i]] = 0
            m[nums[i]] += 1
            if m[nums[i]] > len(nums)/2:
                return nums[i]
        return 0