class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> &visited){
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        
        if(board[i][j] == 'X' || visited[i][j]) return;
        
        visited[i][j] = 1;
        
        dfs(i+1,j,board,visited);
        dfs(i,j+1,board,visited);
        dfs(i-1,j,board,visited);
        dfs(i,j-1,board,visited);
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int i = 0 ; i < m ; i++) dfs(i,0,board,visited);
        for(int i = 0 ; i < n ; i++) dfs(0,i,board,visited);
        
        for(int i = 0 ; i < m ; i++) dfs(i,n-1,board,visited);
        for(int i = 0 ; i < n ; i++) dfs(m-1,i,board,visited);
        
//         for(auto i:visited){
//             for(auto )
//         }
        
        
        for(int i = 0 ; i < m ; i++){
            
            for(int j = 0 ; j < n ; j++){
                if(visited[i][j] == 0) board[i][j] = 'X';
            }
            
        }
        
        
        
    }
};