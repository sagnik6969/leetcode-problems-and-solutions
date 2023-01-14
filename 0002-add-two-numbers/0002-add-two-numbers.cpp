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


ListNode* insert(ListNode* prev,int n){
    
    ListNode* L = new ListNode(n);
    
    if(prev != nullptr) prev->next = L;
    
    return L;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        
        while(l1 != nullptr && l2 != nullptr){
            
            int curr = l1->val + l2->val + carry;
            
            carry = curr/10;
            
            prev = insert(prev,curr%10);
            
            if(head == nullptr) head = prev;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != nullptr){
           int curr = l1->val + carry;
            
            carry = curr/10;
            
            prev = insert(prev,curr%10);
            
            if(head == nullptr) head = prev;
            
            l1 = l1->next;
         
        }
        
        while(l2 != nullptr){
           int curr = l2->val + carry;
            
            carry = curr/10;
            
            prev = insert(prev,curr%10);
            
            if(head == nullptr) head = prev;
            
            l2 = l2->next;
        }
        
       if(carry != 0) insert(prev,carry) ;
        
       return head; 
    }
};