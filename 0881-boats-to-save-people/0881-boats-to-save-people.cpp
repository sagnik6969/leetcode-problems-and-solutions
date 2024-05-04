class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        multiset<int,greater<int>> st;
        for(auto i:people) st.insert(i);
        int ans = 0;
        while(!st.empty()){
            int curr = *st.begin();
         //   cout << curr ;
            st.erase(st.begin());
            ans++;

            int empty_weight = limit - curr;
            auto it = st.lower_bound(empty_weight);
           // cout <<" "<<empty_weight << " " <<*it << endl;
            if(it != st.end()) st.erase(it);
        }

        return ans;
        
    }
};