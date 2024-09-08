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
    int calculate_length(ListNode* head){
        int length = 0;
    
        while(head != nullptr){
            length++;
            head = head -> next;
        }

        return length;
    
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int total_length = calculate_length(head);
        int length = total_length / k;
        int extra = total_length - length * k;
        vector<ListNode*> ans;

        for(int i = 0 ; i < k ; i++){
            ans.push_back(head);
            if(head == nullptr) continue;
            int cnt = length;
            if(extra != 0){
                extra --;
                cnt++;
            }
            ListNode* prev = nullptr;
            while(cnt != 0){
                cnt--;
                prev = head;
                head = head -> next;
            }
            prev -> next = nullptr;
        }

        return ans;

    }
};