class Solution {
public:
    
    bool is_safe(vector<string> arr,int x,int y,int n){
        
    //for(auto i:arr) cout << i << endl;
    
    for(int i = 0 ; i < n ; i++){
        
        if(arr[x][i] == 'Q') return false;
        if(arr[i][y] == 'Q') return false;
        
        //cout << i << " " << x << " " << arr[x][i] << " " << arr[i][x] << endl;
        
    }
        
    int i = x;
    int j = y;
        
    while(i < n && j < n){
        if(arr[i][j] == 'Q') return false;
        i++;
        j++;
    }
        
        i = x;
        j = y;
        
    while(i >= 0 && j >= 0){
        if(arr[i][j] == 'Q') return false;
        i--;
        j--;
    }
        
        i = x;
        j = y;
        
    while(i < n && j >= 0){
        if(arr[i][j] == 'Q') return false;
        i++;
        j--;
    }
        
        i = x;
        j = y;
        
    while(i >= 0 && j < n){
        if(arr[i][j] == 'Q') return false;
        i--;
        j++;
    }
        
   
        
    return true;
        
    }
    
    
    
    void find_sol(vector<string> &arr,int idx,vector<vector<string>> &ans){
        
        if(idx == arr.size()){
            ans.push_back(arr);
            return;
        }
        
        
        for(int i = 0 ; i < arr.size() ; i++){
            if(is_safe(arr,idx,i,arr.size())){
                arr[idx][i] = 'Q';
                find_sol(arr,idx+1,ans);
                arr[idx][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string s = "";
        
        for(int i = 0 ; i < n ; i++) s.push_back('.');
    
        
        vector<string> arr(n,s);
        
//         arr[0][0] = 'Q';
        
         //cout << is_safe({"Q...","Q...","Q...","...."},3,0,n) << endl;
        
        vector<vector<string>> ans;
        find_sol(arr,0,ans);
        
        return ans;
        
        
    }
};