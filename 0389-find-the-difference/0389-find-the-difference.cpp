class Solution {
public:
    
    char better_approach(string &s,string &t){
        
        char ans = 0;
        for(auto i:s) ans ^= i;
        for(auto i:t) ans ^= i;
        
        return ans;
        
    }
    
    char findTheDifference(string s, string t) {
        
      return better_approach(s,t);
        
      int arr[26] = {0};
        
      for(auto i:s) arr[i-'a']++;
      for(auto i:t) arr[i-'a']--;
        
      for(int i = 0 ; i < 26 ; i++){
          if(arr[i] != 0) return (i + 'a');
      }
      
        return -1;
    }
};