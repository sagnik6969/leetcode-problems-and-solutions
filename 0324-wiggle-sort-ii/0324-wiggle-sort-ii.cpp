class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        priority_queue<int,vector<int>> q;
        
        for(auto i:nums) q.push(i);
        
        for(int i = 1 ; i < nums.size() ; i += 2){
            nums[i] = q.top();
            q.pop();
        }
        
        for(int i = 0 ; i < nums.size() ; i+= 2){
            nums[i] = q.top();
            q.pop();
        }
        
        
        
    }
};