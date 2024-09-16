class Solution {
public:
    int get_minutes(string &time){
        return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end(),[&](string &s1,string &s2){
            return get_minutes(s1) < get_minutes(s2);
        });

    int ans = INT_MAX;

    for (int i = 0 ; i < timePoints.size() - 1 ; i++){
        int curr = get_minutes(timePoints[i+1]) - get_minutes(timePoints[i]);
        curr = min(curr, 24 * 60 - curr);
        ans = min(ans,curr);
    }

    int curr = get_minutes(timePoints.back()) - get_minutes(timePoints[0]);
    curr = min(curr, 24 * 60 - curr);
    ans = min(ans,curr);

    return ans;

    }
};