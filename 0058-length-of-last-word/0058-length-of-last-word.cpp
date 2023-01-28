class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int begin = 0;
        int end = s.size()-1;
        
        while(end != 0 && s[end] == ' ') end--;
        
        for(int i = 0 ; i <= end ; i++){
            if(s[i] == ' ') begin = i+1;
        }
        
        return end-begin+1;
        
        
    }
};