class Solution {
public:
    
    int number_of_ones(int n){
        
        int res = 0;
        
        while(n != 0){
            
            res += (n % 2);
            
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