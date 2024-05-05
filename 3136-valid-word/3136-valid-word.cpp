class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        
        for(auto i:word){
            if(!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))) return false;
        }
        
        int vowel = 0;
        int con = 0;
        
        for(auto i:word){
            if(i == 'a' || i == 'e'|| i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E'|| i == 'I' || i == 'O' || i == 'U') vowel++;
            else if((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')) con++;
            
            if(vowel != 0 && con != 0) return true;
        }
        
        return false;
        
        
    }
};