/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
    if head.Next == nil{return head}
    dummy := &ListNode{
        Val: -1000,
        Next : head,
    }
    tmp := dummy

    for i := 0; i < left-1; i++{
        tmp = tmp.Next
    }
   // return tmp

    var nextNode *ListNode = nil
    var prev *ListNode = nil
    current := tmp.Next
    for i := 0; i < right-left+1; i++{
        nextNode = current.Next
        current.Next = prev
        prev  = current
        current = nextNode
    }
    tmp.Next = prev
    tmpTmp := tmp
    for tmpTmp.Next != nil{
        tmpTmp = tmpTmp.Next
    }
    tmpTmp.Next = nextNode
    return dummy.Next
}