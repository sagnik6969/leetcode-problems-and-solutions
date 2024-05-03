class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        unordered_map<int,int> col;
        unordered_map<int,int> row;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        long long  ans = 0;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    ans += (long long)(row[i]-1) * (long long)(col[j] - 1);
                }
            }
        }

        return ans;
        
    }
};