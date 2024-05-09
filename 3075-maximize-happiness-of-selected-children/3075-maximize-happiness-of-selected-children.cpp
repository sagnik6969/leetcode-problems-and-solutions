class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> q;

        for (auto i:happiness) q.push(i);
        int ans = 0;
        for(int i = 0 ; i < k ; i++){
            int curr = max(0,q.top() - i);
            ans += curr;
            q.pop();
        }

        return ans;
        
    }
};