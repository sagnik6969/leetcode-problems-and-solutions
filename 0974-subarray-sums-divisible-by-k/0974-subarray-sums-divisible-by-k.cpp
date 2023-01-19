class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        int s = 0;
        
        int ans = 0;
        
        for(auto i:nums){
            s += i;

            int curr = s % k;

            ans += cnt[curr-k];
            ans += cnt[curr+k];
            ans += cnt[curr];
            
            cnt[curr]++;
        }
    
        
        return ans;
        
    }
};