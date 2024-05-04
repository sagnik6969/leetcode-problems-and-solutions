class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> m;
        m[0] = 1;
        long long ans = 0;
        int prev = 0;
        for(auto i:word){
            int idx = i - 'a';
            int curr = (prev ^ (1 << idx));
            ans += m[curr];
            for(int i = 0 ; i < 10 ; i++){
                ans += m[(curr ^ (1 << i))];
            }
            m[curr]++;
            prev = curr;

        }

        return ans;



    }
};