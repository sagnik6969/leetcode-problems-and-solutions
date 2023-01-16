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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr) return nullptr;
        
        ListNode* prev = nullptr;
        
        ListNode* curr1;
        ListNode* curr2;
        ListNode* next = head;
        ListNode* newhead = (head -> next != nullptr ? head -> next : head);
        
        while(next != nullptr && next -> next != nullptr){
            
            curr1 = next;
            curr2 = next -> next;
            
            next = curr2 -> next;
            
            curr2 -> next = curr1;
            
            curr1 -> next = next;
            
            if(prev) prev -> next = curr2;
            
            prev = curr1;
    
        }
        
        return newhead;
        
        
    }
};