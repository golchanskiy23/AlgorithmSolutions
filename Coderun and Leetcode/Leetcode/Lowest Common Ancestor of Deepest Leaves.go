/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lcaDeepestLeaves(root *TreeNode) *TreeNode {
    ans , _ := dfs(root)
    return ans
}

func dfs(node *TreeNode) (*TreeNode, int) {
        if node == nil {
            return nil , 0
        }
        leftSubtreeLCA, leftDepth := dfs(node.Left);
        rightSubtreeLCA, rightDepth := dfs(node.Right);
      
        if leftDepth > rightDepth {
            return leftSubtreeLCA, leftDepth + 1;
        } else if leftDepth < rightDepth {
            return rightSubtreeLCA, rightDepth + 1;
        } 
        return node, leftDepth + 1;
}