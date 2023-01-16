class Solution {
public:
    int longestValidParentheses(string s) {
        
        int ans = 0;
        vector<int> st;
        
        for(auto i:s){
            
            if(i == '(') st.push_back(-1);
            else{
                
               if(!st.empty() && st.back() == -1){
                   st.pop_back();
                   st.push_back(2);
               }
               else if(st.size() >= 2 && st.back() > 0 && st[st.size() - 2] == -1){
                        
                        int curr = st.back();
                        st.pop_back();
                        st.pop_back();
                        st.push_back(curr + 2);

               }
               else st.push_back(-2);
               
               if(st.size() >= 2 && st.back() > 0 && st[st.size() - 2] > 0){
                   st[st.size() - 2] += st.back();
                   st.pop_back();
               }
                
            }
            
        }

        while(st.empty() == 0){

            cout << st.back() << " ";
            ans = max(ans,st.back());
            st.pop_back();
        }
        
        return ans;
        
    }
};