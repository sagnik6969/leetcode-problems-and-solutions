class Solution {
public:
    int case_a(string &s){
        int cnt_0 = 0;
        int cnt_1 = 0;

        for(int i = 0 ; i < s.size() ; i++){
            if(i % 2 == 0 && s[i] == '0') cnt_0++;
            if(i%2 != 0 && s[i] == '1') cnt_1++;
        }

        if(cnt_0 == cnt_1) return cnt_0;
        return INT_MAX;
    }
    int case_b(string &s){
        int cnt_0 = 0;
        int cnt_1 = 0;

        for(int i = 0 ; i < s.size() ; i++){
            if(i % 2 != 0 && s[i] == '0') cnt_0++;
            if(i%2 == 0 && s[i] == '1') cnt_1++;
        }

        if(cnt_0 == cnt_1) return cnt_0;
        return INT_MAX;
    }
    int minSwaps(string s) {

        int ans1 = case_a(s);
        int ans2 = case_b(s);

        int ans = min(ans1,ans2);

        return ans == INT_MAX ? -1 : ans;

        
        
    }
};