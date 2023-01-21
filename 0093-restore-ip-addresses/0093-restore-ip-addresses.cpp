class Solution {
public:
    
    void rec(int idx,string &s,vector<string> &ans,vector<string> &curr){
        
        if(curr.size() > 4) return;
        
        if(idx >= s.size()){
            
            if(curr.size() != 4) return;
            
            string x = "";
            
            x += curr[0];
            
            for(int i = 1 ; i < curr.size() ; i++) {
                x += '.';
                x += curr[i];
            }
            
            ans.push_back(x);
            
            return;
         }
        
        
        curr.push_back(s.substr(idx,1));
        rec(idx+1,s,ans,curr);
        curr.pop_back();

        if(s[idx] == '0') return;
        
        if(idx+1 < s.size()){
            
            curr.push_back(s.substr(idx,2));
            rec(idx+2,s,ans,curr);
            curr.pop_back();
            
        }
        
         if(idx+2 < s.size() && stoi(s.substr(idx,3)) <= 255){
            
            curr.push_back(s.substr(idx,3));
            rec(idx+3,s,ans,curr);
            curr.pop_back();
            
        }        
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> curr;
        vector<string> ans;
        
        rec(0,s,ans,curr);
        
        return ans;

        
        
    }
};