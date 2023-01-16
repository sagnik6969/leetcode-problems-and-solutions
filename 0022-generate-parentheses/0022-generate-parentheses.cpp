class Solution {
public:
    
    void rec(int n,int o,string &curr,vector<string> &ans){
        
        if(n == 0 && o == 0){
            ans.push_back(curr);
            return;
        }
        
        if(n != 0){
            curr.push_back('(');
            rec(n-1,o+1,curr,ans);
            curr.pop_back();
        }
        
        if(o != 0){
            
             curr.push_back(')');
             rec(n,o-1,curr,ans);
             curr.pop_back();
            
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        string curr = "";
        vector<string> ans;
        
        rec(n,0,curr,ans);
        
        return ans;
        
    }
};