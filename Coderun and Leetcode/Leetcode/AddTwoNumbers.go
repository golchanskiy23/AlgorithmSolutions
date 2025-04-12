/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    remains := 0
    tmp := &ListNode{
        Val : 0,
        Next: nil,
    }
    ans := tmp
    for l1 != nil && l2 != nil{
        t := l1.Val+l2.Val+remains
        newNode := &ListNode{
            Val: t%10,
            Next: nil,
        }
        ans.Next = newNode
        remains = t / 10
        l1, l2, ans = l1.Next, l2.Next, ans.Next
    }

    for l1 != nil{
        t := l1.Val+remains
        newNode := &ListNode{
            Val: t%10,
            Next: nil,
        }
        ans.Next = newNode
        remains = t / 10
        l1, ans = l1.Next, ans.Next
    }

    for l2 != nil{
        t := l2.Val+remains
        newNode := &ListNode{
            Val: t%10,
            Next: nil,
        }
        ans.Next = newNode
        remains = t / 10
        l2, ans = l2.Next, ans.Next
    }
    if remains != 0{
        newNode := &ListNode{
            Val: remains,
            Next: nil,
        }
        ans.Next = newNode
    }

    return tmp.Next
}