class Solution {
public:
    
    int rec(string &s,int idx,int prev,vector<vector<int>> &dp){
        
        if(idx == s.size()) return 0;
        
        if(dp[idx][prev] != -1) return dp[idx][prev];
        
        if(prev == 0){
            
            if(s[idx] == '0')
                 dp[idx][prev] = min(rec(s,idx+1,0,dp),1 + rec(s,idx+1,1,dp));
            else 
                 dp[idx][prev] = min(rec(s,idx+1,1,dp),1 + rec(s,idx+1,0,dp));
            
        }
        else{
            
            if(s[idx] == '0')
                 dp[idx][prev] = 1 + rec(s,idx+1,1,dp);
            else 
                 dp[idx][prev] = rec(s,idx+1,1,dp);
             
        }
        
        return dp[idx][prev];
    }
    
    int minFlipsMonoIncr(string s) {
        
      vector<vector<int>> dp(s.size(),vector<int>(2,-1));
        
      return rec(s,0,0,dp);
        
    }
};