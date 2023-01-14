class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0;
        int sign = 1;
        int res = 0;
        
        while(i < s.size() && s[i] == ' ') i++;
        
        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            
            sign = s[i] == '+' ? 1 : -1;
            
            i++;
        }
        
        
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            
            int curr = sign * (s[i] - '0');
            
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && curr > 7)) return INT_MAX;
            if(res < INT_MIN / 10 || (res == INT_MIN / 10 && curr < -8)) return INT_MIN;
            
            res = 10 * res + curr;
            
            i++;
            
        }
        
        return res;
        
        
    }
};