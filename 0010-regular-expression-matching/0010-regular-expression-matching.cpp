class Solution {
public:
    
    bool check(string &str,int idx){
        
        while(idx < str.size()){
            
            if(idx+1 < str.size() && str[idx+1] == '*') idx += 2;
            else return false;
        }
        
        return true;
        
    }
    
    bool is_same(char c1,char c2){
        if(c1 == '.' || c2 == '.') return true;
        return (c1 == c2);
    }
    
    
    bool rec(string &s,string &p,int idx1,int idx2,vector<vector<int>> &dp){

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(idx1 == s.size()){

            if(idx2 == p.size()){ 
                dp[idx1][idx2] = 1;
                return true;
            }
            
            if(check(p,idx2)){
                 
                 dp[idx1][idx2] = 1;
                 return true;
                 
            }

            dp[idx1][idx2] = 0;
            return false;
        }
        
        if(idx2 == p.size()){ 
            dp[idx1][idx2] = 0;
            return false;
        }
        
        if(idx2 + 1 < p.size() && p[idx2+1] == '*'){
         if(is_same(s[idx1],p[idx2])) 
             dp[idx1][idx2] = (rec(s,p,idx1,idx2+2,dp) || rec(s,p,idx1+1,idx2,dp));
         
         else dp[idx1][idx2] = rec(s,p,idx1,idx2+2,dp);
            
         return dp[idx1][idx2];
        }
        
        if(is_same(s[idx1],p[idx2])){ 
            
            dp[idx1][idx2] = rec(s,p,idx1 + 1,idx2 + 1,dp);
        
            return dp[idx1][idx2];

        }

        dp[idx1][idx2] = 0;

        return false;
        
    }
    
    bool isMatch(string s, string p) {
        
        int m = s.size();
        int n = p.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return rec(s,p,0,0,dp);
        
    }
};