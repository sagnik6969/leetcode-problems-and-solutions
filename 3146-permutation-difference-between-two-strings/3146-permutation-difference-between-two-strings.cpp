class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char,int> m;
        for(int i = 0 ; i < s.size() ; i++){
            m[s[i]] = i;
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < t.size() ; i++){
           // cout << i << " " << m[t[i]] << endl;
            ans += abs(i-m[t[i]]);
        }
        
        return ans;
        
    }
};