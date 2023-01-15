//revise

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> mat(n,vector<int>(n,0));
        
        for(auto &i:queries){
            
            int r1 = i[0];
            int c1 = i[1];
            int r2 = i[2];
            int c2 = i[3];
            for(int x = r1 ; x <= r2; x++){
                mat[x][c1]++;
                if(c2 + 1 < n) mat[x][c2+1]--;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < n ; j++){
                mat[i][j] += mat[i][j-1];
            }
        }    
        return mat;
    }
    
};