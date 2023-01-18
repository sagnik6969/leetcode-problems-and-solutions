class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        long long max_sum = INT_MIN;
        long long min_sum = INT_MAX;
        
        long long s = 0;
        
        for(auto i:nums){
            s += i;
            max_sum = max(max_sum,s);
            if(s < 0) s = 0;
        }
        
        s = 0;
        
        for(int i = 1 ; i < nums.size()-1 ; i++){
            s += nums[i];
            min_sum = min(min_sum,s);
            if(s > 0) s = 0;
        }
        
        int sum = 0;
        
        for(auto i:nums) sum += i;
        
     
        
        
        return max(max_sum,sum - min_sum);
        
    }
};