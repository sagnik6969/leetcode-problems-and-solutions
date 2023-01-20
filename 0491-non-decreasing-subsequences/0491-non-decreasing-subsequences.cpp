class Solution {
public:
    
    void rec(int idx,vector<int> &arr,vector<int> &curr,set<vector<int>> &ans){
        
        if(idx == arr.size()){
            if(curr.size() > 1) ans.insert(curr);
            return;
        }
        
        rec(idx+1,arr,curr,ans);
        
        if(curr.empty() || curr.back() <= arr[idx]){
            curr.push_back(arr[idx]);
            rec(idx+1,arr,curr,ans);
            curr.pop_back();
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int> curr;
        set<vector<int>> ans;
        
        rec(0,nums,curr,ans);
        
        vector<vector<int>> final_ans;
        
        for(auto &i:ans) final_ans.push_back(i);
        
        return final_ans;
        
    }
};