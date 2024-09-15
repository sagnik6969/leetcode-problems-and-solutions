class Solution {
public:
    int num(char c){
        
        if(c == 'a') return 0;
        if(c == 'e') return 1;
        if(c == 'i') return 2;
        if(c == 'o') return 3;
        if(c == 'u') return 4;
        return -1;
    }

    int findTheLongestSubstring(string s) {

        vector<int> arr;
        unordered_map<int,int> m;
        int vwl_cnt = 0;
        m[0] = -1;

        int ans = 0;

        for(int i = 0 ; i < s.size() ; i++){
            int x = num(s[i]);
            if(x == -1){
              ans = max(ans,i - m[vwl_cnt]);
              continue;
            } 
            vwl_cnt = vwl_cnt ^ (1 << x);
            
            if(m.find(vwl_cnt) != m.end()){
                ans = max(ans,i - m[vwl_cnt]);
            }
            else m[vwl_cnt] = i;
        }


        return ans;

        

        
    }
};