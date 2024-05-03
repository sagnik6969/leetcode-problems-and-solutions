class Solution {
public:
    bool is_possible(vector<vector<char>>& grid,int i,int j){

        int B = 0;
        int W = 0;

        if(grid[i][j] == 'B') B++;
        else W++;

        if(grid[i][j+1] == 'B') B++;
        else W++;

        if(grid[i+1][j] == 'B') B++;
        else W++;

        if(grid[i+1][j+1] == 'B') B++;
        else W++;

        return B == 1 || W == 1;


    }
    bool canMakeSquare(vector<vector<char>>& grid) {
        if(is_possible(grid,0,0)) return true;
        if(is_possible(grid,0,1)) return true;
        if(is_possible(grid,1,0)) return true;
        if(is_possible(grid,1,1)) return true;
        return false;
    }
};