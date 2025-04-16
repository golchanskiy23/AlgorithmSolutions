/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func divide(l,r int, nums []int) *TreeNode{
    if l > r{return nil}
    mid := l+(r-l)/2
    leftSubTree , rightSubTree := divide(l, mid-1, nums), divide(mid+1, r, nums)
    return &TreeNode{
        Val: nums[mid],
        Left: leftSubTree,
        Right: rightSubTree,
    }
}

func sortedArrayToBST(nums []int) *TreeNode {
    n := len(nums)
    return divide(0, n-1, nums)
}