class Solution {
public:
    bool is_safe(vector<vector<int>>& grid,int i,int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        if(grid[i][j] == 0) return false;
        return true;
    }

    int bc(vector<vector<int>>& grid,int i,int j){
        if(!is_safe(grid,i,j)) return 0;

        int ans = grid[i][j];
        grid[i][j] = 0;
        int mx = 0;
        
        mx = max(mx,bc(grid,i+1,j));
        mx = max(mx,bc(grid,i-1,j));
        mx = max(mx,bc(grid,i,j+1));
        mx = max(mx,bc(grid,i,j-1)); 

        grid[i][j] = ans;
        ans += mx;

        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                ans = max(ans,bc(grid,i,j));
            }
        }
        
        return ans;
    }
};