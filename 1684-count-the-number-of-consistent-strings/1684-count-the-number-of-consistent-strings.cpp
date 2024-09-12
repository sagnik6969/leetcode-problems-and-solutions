class Solution {
public:
    bool ch(vector<int> &dict,string &word){
        for(auto &i:word){
            if(dict[i - 'a'] != 1) return false;
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> dict(26,0);
        for(auto i:allowed) dict[i - 'a'] = 1;

        int cnt = 0;
        for(auto &w:words){
           if(ch(dict,w)) cnt++;
        }

        return cnt;
    }
};