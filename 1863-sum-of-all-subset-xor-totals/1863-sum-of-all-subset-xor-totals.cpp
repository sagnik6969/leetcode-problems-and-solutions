class Solution {
public:
    void f(vector<int>& nums,int &ans,int curr_xor,int idx){
        if(idx == nums.size()){
            ans += curr_xor;
            return;
        }

        f(nums,ans,curr_xor,idx+1);
        curr_xor ^= nums[idx];
        f(nums,ans,curr_xor,idx+1);

    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;

        f(nums,ans,0,0);

        return ans;
    }
};