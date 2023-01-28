class Solution {
public:
    
    bool is_safe(vector<string> &arr,int x,int y,int n){
    
    for(int i = 0 ; i < n ; i++){
        
        if(arr[x][i] == 'Q') return false;
        if(arr[i][y] == 'Q') return false; 
        
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
    
    
    
    void find_sol(vector<string> &arr,int idx,int &ans){
        
        if(idx == arr.size()){
            ans++;
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
    
    
    int totalNQueens(int n) {
        string s = "";
        
        for(int i = 0 ; i < n ; i++) s.push_back('.');
        vector<string> arr(n,s);
        int ans = 0;
        
        find_sol(arr,0,ans);
        
        return ans;
    }
};