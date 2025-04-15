/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil{return head}
    m := make(map[int]int)
    tmp := head
    for tmp != nil{
        m[tmp.Val]++
        tmp = tmp.Next
    }
    tmp, newNode := head, &ListNode{Val:-200, Next: nil,}
    tmpNewNode := newNode
    for tmp != nil{
        if m[tmp.Val] == 1{
            currNode :=  &ListNode{
                Val: tmp.Val,
                Next: nil,
            }
            tmpNewNode.Next = currNode
            tmpNewNode = tmpNewNode.Next
        }
        tmp = tmp.Next
    }
    return newNode.Next
}