class Solution {
public:
    bool is_pal(string &s,int i,int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;

    }

    void rec(string &s,vector<vector<string>> &ans,vector<string> &curr_v,string &curr_s,int idx){
        if(idx == s.size()) {
            if(curr_s == "") ans.push_back(curr_v);
            return;
        }

        curr_s.push_back(s[idx]);
        rec(s,ans,curr_v,curr_s,idx+1);

        if(is_pal(curr_s,0,curr_s.size() - 1)) {
           string temp = "";
           curr_v.push_back(curr_s);
           rec(s,ans,curr_v,temp,idx+1);
           curr_v.pop_back();
        }



        curr_s.pop_back();


    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> curr_v;
        string curr_s = "";

        rec(s,ans,curr_v,curr_s,0);
        
        return ans;
    }
};