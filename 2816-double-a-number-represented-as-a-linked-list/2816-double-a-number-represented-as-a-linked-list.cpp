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
    int f(ListNode* head){
        if(head -> next == nullptr){
            int val = head -> val * 2;
            head -> val = val % 10;
            return val / 10;
        }

        int carry = f(head -> next);
        int val = head -> val * 2 + carry;
        head -> val = val % 10;
        return val / 10;
    } 
    ListNode* doubleIt(ListNode* head) {
        int carry = f(head);

        while(carry != 0){
            ListNode* n = new ListNode(carry % 10);
            carry /= 10;
            n -> next = head;
            head = n;
        }

        return head;
    }
};