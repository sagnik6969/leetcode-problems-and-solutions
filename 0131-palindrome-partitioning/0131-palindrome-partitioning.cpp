class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool is_pal(string &s,int i,int j){
        
        if(i >= j) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return (s[i] == s[j]) && is_pal(s,i+1,j-1);
        
    }
    
    void rec(int idx,string &s,vector<string> &curr,vector<vector<string>> &ans){
        
        if(idx == s.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i = idx ; i < s.size() ; i++){
            
            if(is_pal(s,idx,i)){
                curr.push_back(s.substr(idx,i - idx + 1));
                rec(i+1,s,curr,ans);
                curr.pop_back();
            }
            
        }
        
        
    }
    
    
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        
        vector<string> curr;
        vector<vector<string>> ans;
        
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        
        rec(0,s,curr,ans);
        
        return ans;
        
    }
};