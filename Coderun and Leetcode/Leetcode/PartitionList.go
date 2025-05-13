/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    beforeHead, afterHead := &ListNode{}, &ListNode{}
    before , after := beforeHead, afterHead
    for head != nil{
        currNode := &ListNode{
            Val: head.Val,
            Next: nil,
        }

        if head.Val < x{
            before.Next = currNode
            before = before.Next
        } else{
            after.Next = currNode
            after = after.Next
        }
        head = head.Next
    }
    before.Next = afterHead.Next
    return beforeHead.Next
}