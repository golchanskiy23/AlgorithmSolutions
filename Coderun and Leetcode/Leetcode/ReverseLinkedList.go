/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func size(head *ListNode) int{
    tmp, s := head, 0;
    for tmp != nil{
        s++
        tmp = tmp.Next
    }
    return s
}

func reverseListHelper(prev, head, rest *ListNode) *ListNode{
    if rest == nil{return head}
    nextRest := rest.Next
    rest.Next = head
    head.Next = prev
    return reverseListHelper(head,rest,nextRest)
}

func reverseList(head *ListNode) *ListNode {
    if head == nil || size(head) == 1{return head}
    return reverseListHelper(nil, head, head.Next)
}