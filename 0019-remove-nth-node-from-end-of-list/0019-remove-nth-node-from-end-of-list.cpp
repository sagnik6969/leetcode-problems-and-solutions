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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* curr1 = head;
        
        for(int i = 0 ; i < n ; i++) curr1 = curr1 -> next;
        
        if(curr1 == nullptr) return head -> next;
        
        ListNode* curr2 = head;
        
        while(curr1 -> next != nullptr){
            curr2 = curr2 -> next;
            curr1 = curr1 -> next;
        }
        
        curr2 -> next = curr2 -> next -> next;
        
        return head;
        
    }
};