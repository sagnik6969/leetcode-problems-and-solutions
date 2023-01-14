class Solution {
public:
    
    bool check_palendrom(string &s,int i,int j,vector<vector<int>> &dp){
        
        if(i >= j) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = (s[i] == s[j] && check_palendrom(s,i+1,j-1,dp));
     
        return dp[i][j];
    } 
    
    
   
    
    
    string longestPalindrome(string s) {
         
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        
         int n = s.size();
        
        int ans_size = 0;
        
        int x;
        int y;
        
        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                
                if(check_palendrom(s,i,j,dp) && ans_size < (j-i+1)){
                    x = i;
                    y = j;
                    ans_size = j-i+1;
                }
                
            }
        }
        
        string ans = s.substr(x,y-x+1);
        
        return ans;
        
        
    }
};