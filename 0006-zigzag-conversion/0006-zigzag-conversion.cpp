class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        
        string ans = "";
        
        int inc1 = 2*numRows - 2;
        
        for(int i = 0 ; i < numRows ; i++){
            
            int inc2 = 2*(numRows-i-1);
            
            for(int j = i ; j < s.size() ; j += inc1){
                
                ans += s[j];
                
                if(j + inc2 < s.size() && i != 0 && i != numRows - 1) ans += s[j+inc2];
                
            }
            
            
        }
        
        return ans;
        
    }
};