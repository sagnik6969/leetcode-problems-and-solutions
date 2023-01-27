class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n <= 0 || (n & (n-1)) != 0) return false;
        
        int curr =log2(n);
        
        return (curr % 2 == 0);
    }
};