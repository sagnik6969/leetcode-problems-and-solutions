class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(auto i:nums) x ^= i;
        x ^= k;
        int ans = 0;

        while(x != 0){
            ans += (x & 1);
            x >>= 1;
        }
        return ans;
    }
};