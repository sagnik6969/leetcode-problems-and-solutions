class Solution {
public:
    
    vector<int> better_approach(int n){
        
        vector<int> ans(n + 1,0);
        
        for(int i = 0 ; i <= n ; i++){
            
            if(i & 1) ans[i] = ans[i-1] + 1;
            else ans[i] = ans[i/2];
            
        }
        
        return ans;
        
    }
    
    
    int number_of_ones(int n){
        
        int res = 0;
        
        while(n != 0){
            
            res += (n&1);
            
            n >>= 1;
            
        }
        
        return res;
        
        
    }
    
    vector<int> countBits(int n) {
        
        vector<int> arr(n + 1);
        
        for(int i = 0 ; i <= n ; i++){
            arr[i] = number_of_ones(i);
        }
        
        return arr;
        
    }
};