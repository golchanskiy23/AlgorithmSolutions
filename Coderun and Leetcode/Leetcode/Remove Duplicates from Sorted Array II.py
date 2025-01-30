class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        m = {}
        arr = []
        cnt  = 0
        for i in range(0, len(nums)):
            if nums[i] not in m:
                m[nums[i]] = 0
            m[nums[i]] += 1
            if m[nums[i]] <= 2:
                arr.append(nums[i])
                cnt += 1
        for i in range(0, len(arr)):
            nums[i] = arr[i]
        return cnt
            
