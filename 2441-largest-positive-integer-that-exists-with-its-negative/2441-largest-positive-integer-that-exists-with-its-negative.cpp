class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;

        int ans = -1;

        for(auto i:nums){
            if(s.find(-i) != s.end()){
                ans = max(ans,abs(i));
               
            } else s.insert(i);
        }

        return ans;
        
    }
};