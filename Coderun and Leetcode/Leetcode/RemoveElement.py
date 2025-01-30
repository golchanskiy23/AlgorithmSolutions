class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        l,r, cnt = 0, len(nums)-1, 0

        while l <= r:
            if nums[r] == val:
                r -= 1
                cnt += 1
            elif nums[l] == val and nums[r] != val:
                nums[l], nums[r] = nums[r], nums[l]
                r -= 1
                l += 1
                cnt += 1
            else:
                l += 1
        return len(nums)-cnt