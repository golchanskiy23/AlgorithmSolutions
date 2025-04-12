/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    ans := &ListNode{
        Val: 0,
        Next: nil,
    }

    tmp := ans
    for list1 != nil && list2 != nil{
        var currNode *ListNode
        if list1.Val < list2.Val{
            currNode = &ListNode{
                Val : list1.Val,
                Next: nil,
            }
            list1 = list1.Next
        } else{
            currNode = &ListNode{
                Val : list2.Val,
                Next: nil,
            }
            list2 = list2.Next
        }
        tmp.Next = currNode
        tmp = tmp.Next
    }

    for list1 != nil{
         currNode := &ListNode{
                Val : list1.Val,
                Next: nil,
        }
        list1 = list1.Next
        tmp.Next = currNode
        tmp = tmp.Next
    }

    for list2 != nil{
         currNode := &ListNode{
                Val : list2.Val,
                Next: nil,
        }
        list2 = list2.Next
        tmp.Next = currNode
        tmp = tmp.Next
    }

    return ans.Next
}