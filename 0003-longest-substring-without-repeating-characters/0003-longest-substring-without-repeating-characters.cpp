class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> cnt;
        
        int i = 0;
        int j = 0; 
        int ans = 0;
        
        while(j < s.size()){
            
            cnt[s[j]]++;
            int ch = s[j];
            j++;
            
            while(cnt[ch] > 1){
                cnt[s[i]]--;
                i++;
            }
            ans = max(ans,j - i);
        }
        
        return ans;
        
    }
};