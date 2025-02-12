class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        size  = len(nums)
        if k%size == 0 or k == 0 or size == 1:
            return
        i, k = 0, k%size
        while i < size/2:
            nums[i], nums[size-1-i] = nums[size-1-i], nums[i]
            i += 1
        i = 0
        while i < k/2:
            nums[i], nums[k-1-i] = nums[k-1-i], nums[i]
            i += 1
        i, start = 0,k
        while i < (size-k)/2:
            nums[start], nums[size-1-i] = nums[size-1-i], nums[start]
            i += 1
            start += 1