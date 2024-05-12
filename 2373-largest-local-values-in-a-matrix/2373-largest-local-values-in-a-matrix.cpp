class Solution {
public:
    int get_max(vector<vector<int>>& grid,int i,int j){
        int mx = INT_MIN;
        for(int x = i-1 ; x <= i+1 ; x++){
            for(int y = j-1 ; y <= j+1 ; y++){
                mx = max(mx,grid[x][y]);
            }
        }

        return mx;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        
        for(int i = 0 ; i < ans.size() ; i++){
            for(int j = 0 ; j < ans[0].size() ; j++){
                ans[i][j] = get_max(grid,i+1,j+1);
            }
        }
        return ans;
    }
};