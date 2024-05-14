class Solution {
public:
    void flip_row(vector<vector<int>>& grid,int row){
        for(int i = 0 ; i < grid[0].size() ; i++) grid[row][i] = !grid[row][i];
    }

    void flip_col(vector<vector<int>>& grid,int col){
        for(int i = 0 ; i < grid.size() ; i++) grid[i][col] = !grid[i][col];
    }

    // void count_row_1(vector<vector<int>>& grid,int row){
    //     int ans = 0;
    //     for(int i = 0 ; i < grid[0].size() ; i++) ans += grid[row][i];
    //     return ans;
    // }

    // void count_col_1(vector<vector<int>>& grid,int col){
    //     int ans = 0;
    //     for(int i = 0 ; i < grid.size() ; i++) ans += grid[i][col];
    //     return ans;
    // }

    int matrixScore(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            if(grid[i][0] == 0) flip_row(grid,i);
        }

        ans += grid.size() * (1 << (grid[0].size() - 1));

        for(int j = 1 ; j < grid[0].size() ; j++){
            int cnt = 0;
            for(int i = 0 ; i < grid.size() ; i++){
                cnt += grid[i][j];
            }

            ans += max(cnt,(int)grid.size()-cnt) * (1 << (grid[0].size() - j - 1));


        }
        return ans;
    }
};