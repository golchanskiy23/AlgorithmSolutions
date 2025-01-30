class Solution:
    def merge(self, arr1: List[int], m: int, arr2: List[int], n: int) -> None:
        i1, i2, idx = m-1, n-1, n+m-1
        while i1 >= 0 and i2 >= 0:
            if arr2[i2] > arr1[i1]:
                arr1[idx]=arr2[i2]
                i2 -= 1
                idx -= 1
            else:
                arr1[idx]=arr1[i1]
                i1 -= 1
                idx -= 1
        while i2 >= 0:
            arr1[idx]=arr2[i2]
            i2 -= 1
            idx -= 1
        while i1 >= 0:
            arr1[idx]=arr1[i1]
            i1 -= 1
            idx -= 1