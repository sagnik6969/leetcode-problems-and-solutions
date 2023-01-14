class Solution {
public:
    int reverse(int x) {
        
        int res = 0;
        
        while(x != 0){
            
            int curr = x % 10;
            
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && curr > 7)) return 0;
            if(res < INT_MIN / 10 || (res == INT_MIN / 10 && curr < -8)) return 0;
            
            res = 10 * res + curr;
            
            x /= 10;
        }
        
        return res;
        
        
    }
};