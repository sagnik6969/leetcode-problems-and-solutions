class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<vector<int>>& grid,int i,int j){
        
      //  cout << i << " " << j << endl;
        
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int ans = INT_MIN;
        
        if(i+1 < grid.size()) ans = grid[i+1][j]-grid[i][j] + max(0,f(grid,i+1,j));
        if(j+1 < grid[0].size()) ans = max(ans,grid[i][j+1]-grid[i][j] + max(0,f(grid,i,j+1)));
        
       
        
        dp[i][j] = ans;
        
        return ans;
        
    }
    
    int maxScore(vector<vector<int>>& grid) {
        
        dp = vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),INT_MIN));
        int ans = INT_MIN;
        
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ;j++){
             //   if(i == grid.size() - 1|| j == grid[0].size() - 1) continue;
                ans = max(ans,f(grid,i,j));
            }
        }
        
        
        return ans;
    }
};