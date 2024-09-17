class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m;

        string curr = "";
        for(auto i:s1){
            if(i == ' '){
                if(curr != "") m[curr]++;
                curr = "";
            }
            else curr.push_back(i);
        }
        if(curr != "") m[curr]++;

        curr = "";
        for(auto i:s2){
            if(i == ' '){
                if(curr != "") m[curr]++;
                curr = "";
            }
            else curr.push_back(i);
        }
        if(curr != "") m[curr]++;

        vector<string> v;

        for(auto i:m){
            if(i.second == 1) v.push_back(i.first);
        }

        return v;
        
    }
};