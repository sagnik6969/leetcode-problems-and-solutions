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
    ListNode* removeNodes(ListNode* head) {
        if(head -> next == nullptr) return head;
        // if(head -> val < head -> next -> val) 
        // return removeNodes(head -> next);
        ListNode* n = removeNodes(head -> next);
        head -> next = n;
        if(n -> val > head -> val){
             return n;
        } 
            
        return head;
        
    }
};