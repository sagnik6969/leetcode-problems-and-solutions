class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        
        int i;
        
        for(i = 0; i <intervals.size() ; i++){
            if(intervals[i][0] < newInterval[0]){
                ans.push_back(intervals[i]);
            }
            else break;
        }
        
        // if(i == intervals.size()){
        //     ans.push_back(newInterval);
        //     return ans;
        // }
        
        if(ans.empty() || ans.back()[1] < newInterval[0]){
            ans.push_back(newInterval);
        }
        else{
            
            ans.back()[1] = max(ans.back()[1],newInterval[1]);
        }
        
        // for(auto x:ans){
        //     cout << x[0] << " " << x[1] << endl;
        // }
        
        for(;i < intervals.size() ; i++){
            
            if(ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            else ans.push_back(intervals[i]);
            
        }
        
        return ans;
        
        
        
        
    }
};