/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int size(ListNode* head){
        auto curr = head;
        int s = 0;
        while(curr != nullptr){
            curr = curr->next;
            s++;
        }
        return s;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //size-n+1_th node must be deleted
        if(size(head)-n == 0) head = head->next;
        else{
            auto currNode = head;
            ListNode* prevNode = new ListNode(-1,currNode);
            int currIdx = 1, forDelete = size(head)-n+1;
            while(currIdx != forDelete){
                prevNode = prevNode->next;
                currNode = currNode->next;
                ++currIdx;
            }
            
            prevNode->next = currNode->next;
        }
        return head;
    }
};