class Solution {
public:
    
    vector<int> arr;
    
    Solution(vector<int>& nums) {
        
        arr = nums;
        
    }
    
    vector<int> reset() {
        
        return arr;
        
    }
    
    vector<int> shuffle() {
        
        vector<int> v = arr;
        
        vector<int> ans;
        ans.reserve(arr.size());
        
        while(!v.empty()){
            
            int idx = rand() % v.size();
            
            ans.push_back(v[idx]);
            
            v.erase(v.begin()+idx);
            
            
        }
        
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */