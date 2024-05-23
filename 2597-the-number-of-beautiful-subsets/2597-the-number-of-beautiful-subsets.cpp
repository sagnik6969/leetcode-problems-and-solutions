class Solution {
public:
    bool is_valid(int x){
        return x >= 0 && x <= 1000;
    }
    void f(vector<int>& nums, int k,vector<int> curr,int idx,int &ans){
        if(idx == nums.size()){
             ans++;
             return;
        }
        
        f(nums,k,curr,idx+1,ans);

        if((!is_valid(nums[idx]-k) || curr[nums[idx] - k] == 0)
        &&
        (!is_valid(nums[idx]+k) || curr[nums[idx]+k] == 0)){
            curr[nums[idx]]++;
            f(nums,k,curr,idx+1,ans);
            curr[nums[idx]]--;
        }

    }
    int beautifulSubsets(vector<int>& nums, int k) {

        vector<int> curr(1001,0);
        int ans = 0;

         f(nums,k,curr,0,ans);
        return ans - 1;
    }
};