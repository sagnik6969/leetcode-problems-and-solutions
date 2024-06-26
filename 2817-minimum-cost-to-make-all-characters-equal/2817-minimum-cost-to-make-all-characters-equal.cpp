long long better_approach(string &s){

    long long ans = 0;
    
    for(int i = 0 ; i < s.size()-1 ; i++){
           if(s[i] != s[i+1]) ans += min(i+1,(int)s.size()-(i+1));
    }

    return ans;
}



class Solution {
public:
    
    long long f1(string s) {
        
        long long ans = 0;
        
        int i = 0;
        
        while(i < s.size()){
            
         //   cout << i << endl;
            
            if(s[i] == '0'){
                i++;
                continue;
            }
            
            int j = i;
            
            while(i < s.size() && s[i] == '1') i++;
            i--;
            
            int ans1 = i + 1 + j;
            int ans2 = (s.size() - j) + (s.size() - i - 1); 
            ans += min(ans1,ans2);
            i++;
            
        }
        
        return ans;
        
    }
    
    long long f2(string s) {
        
        long long ans = 0;
        
        int i = 0;
        
        while(i < s.size()){
            
         //   cout << i << endl;
            
            if(s[i] == '1'){
                i++;
                continue;
            }
            
            int j = i;
            
            while(i < s.size() && s[i] == '0') i++;
            i--;
            
            int ans1 = i + 1 + j;
            int ans2 = (s.size() - j) + (s.size() - i - 1); 
            ans += min(ans1,ans2);
            i++;
            
        }
        
        return ans;
        
    }
    
    
    
    
    
    long long minimumCost(string s) {

      return better_approach(s);
        
      return  min(f1(s),f2(s));
        
    }
};