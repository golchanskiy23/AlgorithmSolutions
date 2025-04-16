/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func size(head *ListNode) int{
    count := 0
    tmp := head
    for tmp != nil{
        count++
        tmp = tmp.Next
    }
    return count
}

func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil || size(head) == 1 || k%size(head) == 0{return head}
    cycles := k%size(head)
    head1, tmp := head , head
    for i := 0; i < size(head)-cycles-1; i++{
        tmp = tmp.Next
    }
    head2 := tmp.Next
    tmp.Next = nil
    tmp = head2
    for tmp.Next != nil{
        tmp = tmp.Next
    }
    tmp.Next = head1
    return head2
}