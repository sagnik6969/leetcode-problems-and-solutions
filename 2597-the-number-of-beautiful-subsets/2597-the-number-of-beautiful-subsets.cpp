class Solution {
public:
    int f(vector<int>& nums, int k,multiset<int> &curr,int idx){
        if(idx == nums.size()) return curr.empty() ? 0:1;
        
        int ans = f(nums,k,curr,idx+1);

        if(curr.find(nums[idx] - k) == curr.end() && curr.find(nums[idx] + k) == curr.end()){
            curr.insert(nums[idx]);
            ans += f(nums,k,curr,idx+1);
            curr.erase(curr.find(nums[idx]));
        }
        
        return ans;

    }
    int beautifulSubsets(vector<int>& nums, int k) {

        multiset<int> curr;

        return f(nums,k,curr,0);
        
    }
};