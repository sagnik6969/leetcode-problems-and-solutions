class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        
        int i = 0;
        int j = 0;
        long long ans = 0;
        int cnt = 0;
        
        while(j < nums.size()){
            
            m[nums[j]]++;
            cnt += m[nums[j]] - 1;
            j++;
            
            while(cnt >= k){
                cnt -= (m[nums[i]] - 1);
                m[nums[i]]--;
                i++;
            }
            
            ans += i;
            
        }
        
        return ans;
        
    }
};