class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        
        string s = "";
        
        while(x != 0){
            
            s.push_back('0' + x % 10);
            
            x /= 10;
            
        }
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j){
            
            if(s[i] != s[j]) return false;
            i++;
            j--;
            
        }
        
        return true;
        
    }
};