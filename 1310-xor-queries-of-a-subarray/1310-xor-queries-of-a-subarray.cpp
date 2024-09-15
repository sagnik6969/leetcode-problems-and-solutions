class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int x = 0;
        vector<int> v;
        v.reserve(arr.size());

        for(auto i:arr){
            x ^= i;
            v.push_back(x);
        }

        vector<int> ans;
        for(auto i:queries){
            if(i[0] != 0) ans.push_back(v[i[0] - 1] ^ v[i[1]]);
            else ans.push_back(v[i[1]]);
        }
        return ans;
        
    }
};