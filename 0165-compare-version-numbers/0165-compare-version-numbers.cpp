class Solution {
public:
    vector<int> f(string v1){
        vector<int> ans;
        string s = "";
        
        for(auto i:v1){
            if(i == '.'){
                ans.push_back(stoi(s));
                s = "";
            }
            else s.push_back(i);
        }
        
        ans.push_back(stoi(s));
        return ans;
        
    }
    
    int compareVersion(string version1, string version2) {
        
        vector<int> v1 = f(version1);
        vector<int> v2 = f(version2);
        
        int i = 0;
        
        
        while(i < v1.size() || i < v2.size()){
            
            if(i < v1.size() && i < v2.size()){
                if(v1[i] > v2[i]) return 1;
                else if(v1[i] < v2[i]) return -1;
            }
            else if(i < v1.size() && v1[i] != 0) return 1;
            else if(i < v2.size() && v2[i] != 0) return -1;
            i++;
        }
        return 0;
    }
};