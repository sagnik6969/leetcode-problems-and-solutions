class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        vector<pair<int,int>> v;
        v.reserve(arr.size());

        for(int i = 0 ; i < arr.size() ; i++){
            for(int j = i + 1 ; j < arr.size() ; j++){
                v.push_back({arr[i],arr[j]});
            }
        }

        sort(v.begin(),v.end(),[&](pair<int,int> &p1,pair<int,int> &p2){
            return p1.first * p2.second < p2.first * p1.second;
        });

        return {v[k-1].first,v[k-1].second};


        
    }
};