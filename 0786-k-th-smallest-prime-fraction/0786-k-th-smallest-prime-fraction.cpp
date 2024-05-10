vector<int> v;

class compare {
    public:
    bool operator()(pair<int,int> &p1,pair<int,int> &p2){
        return v[p1.first] * v[p2.second] > v[p2.first] * v[p1.second];
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
     v = arr;

     priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q;

     for(int i = 0 ; i < arr.size()-1; i++) q.push({i,arr.size()-1});

     for(int i = 0 ; i < k-1 ; i++){
        int x = q.top().first;
        int y = q.top().second;
        //cout << v[x] << " " << v[y] << endl;
        q.pop();
        y--;

        if(y != x) q.push({x,y});

     }

      return {v[q.top().first],v[q.top().second]};
        
    }
};