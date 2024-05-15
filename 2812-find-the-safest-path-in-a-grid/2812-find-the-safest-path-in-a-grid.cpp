class Solution {
public:
    bool is_safe(vector<vector<int>>& grid, vector<vector<int>>& dist, int i,int j){
        if(i < 0 || 
        j < 0 || 
        i >= grid.size() || 
        j >= grid[0].size() || 
        dist[i][j] != INT_MAX 
        ) return false;

        return true;
    }
    bool is_safe2(vector<vector<int>>& grid, int i,int j){
        if(i < 0 || 
        j < 0 || 
        i >= grid.size() || 
        j >= grid[0].size() 
        ) return false;

        return true;
    }




    bool bfs(vector<vector<int>>& grid, vector<vector<int>>& dist, int min_safeness){
        if(dist[0][0] < min_safeness) return false;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));

        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;

            if(i == grid.size()-1 && j == grid[0].size()-1) return true;

            q.pop();

            if(is_safe2(grid,i+1,j) && visited[i+1][j] == 0 && dist[i+1][j] >= min_safeness){
                q.push({i+1,j});
                visited[i+1][j] = 1;
            }
            if(is_safe2(grid,i,j+1) && visited[i][j+1] == 0 && dist[i][j+1] >= min_safeness){
                q.push({i,j+1});
                visited[i][j+1] = 1;
            }
            if(is_safe2(grid,i-1,j) && visited[i-1][j] == 0 && dist[i-1][j] >= min_safeness){
                q.push({i-1,j});
                visited[i-1][j] = 1;
            }
            if(is_safe2(grid,i,j-1) && visited[i][j-1] == 0 && dist[i][j-1] >= min_safeness){
                q.push({i,j-1});
                visited[i][j-1] = 1;
            }  

        }

// cout << endl;
//         for(auto i:visited){
//             for(auto j:i) cout << j << " ";
//             cout << endl;
//         }

        return false;
                                                                                  

    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));

        queue<pair<int,int>> q;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){ q.push({i,j});
                dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(is_safe(grid,dist,i+1,j)){
                dist[i+1][j] = dist[i][j]+1;
                q.push({i+1,j});
            }
            if(is_safe(grid,dist,i-1,j)){
                dist[i-1][j] = dist[i][j]+1;
                q.push({i-1,j});
            }
            if(is_safe(grid,dist,i,j+1)){
                dist[i][j+1] = dist[i][j]+1;
                q.push({i,j+1});
            }
            if(is_safe(grid,dist,i,j-1)){
                dist[i][j-1] = dist[i][j]+1;
                q.push({i,j-1});
            }

        }


        // for(auto i:dist){
        //     for(auto j:i) cout << j << " ";
        //     cout << endl;
        // }

        int low = 0;
        int high = 2 * grid.size();
        int ans = 0;
       // cout << bfs(grid,dist,1) << endl;
        while(low <= high){
            int mid = (low + high) / 2;
            //cout << mid << endl;
            if(bfs(grid,dist,mid)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }


        return ans;
        
    }
};