class Solution {
public:
    void rec(vector<int>& nums,int idx,vector<int> &curr,vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }

        rec(nums,idx+1,curr,ans);
        curr.push_back(nums[idx]);
        rec(nums,idx+1,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        rec(nums,0,curr,ans);

        return ans;
    }
};