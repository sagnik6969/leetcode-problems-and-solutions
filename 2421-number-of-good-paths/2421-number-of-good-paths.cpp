class Solution {
public:
    
    vector<int> parent;
    vector<int> size;
    vector<int> mx;
    vector<int> mxcnt;
    
    int find_parent(int child){
        
        if(child == parent[child]) return child;
        
        parent[child] = find_parent(parent[child]);
        
        return parent[child];
        
    }
    
    void unite(int n1,int n2){
        
        int p1 = find_parent(n1);
        int p2 = find_parent(n2);
        
        if(p1 == p2) return;
        
        if(size[p2] > size[p1]) swap(p1,p2);
        
        parent[p2] = p1;
        
        size[p1] += size[p2];
        
        if(mx[p1] == mx[p2]){
            mxcnt[p1] += mxcnt[p2];
        }
        else if(mx[p1] < mx[p2]){
            mx[p1] = mx[p2];
            mxcnt[p1] = mxcnt[p2];
        }
    
    }
    
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int n = vals.size();
        
        parent = vector<int>(n);
        size = vector<int>(n);
        mx = vector<int>(n);
        mxcnt = vector<int>(n);
    
        
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            size[i] = 1;
            mx[i] = vals[i];
            mxcnt[i] = 1;
        }
        
        sort(edges.begin(),edges.end(),[&](vector<int> &v1,vector<int> &v2){
            
            return max(vals[v1[0]],vals[v1[1]]) < max(vals[v2[0]],vals[v2[1]]);
            
        });
        
        int ans = n;
        
        for(auto &i:edges){
             
            int n1 = find_parent(i[0]);
            int n2 = find_parent(i[1]);
            
            
           // cout << n1 << " " << n2 << " " << mx[n1] << " " << mx[n2] << endl;
            
            
            
            if(mx[n1] == mx[n2]){
                ans += mxcnt[n1] * mxcnt[n2];
            }
            
            unite(n1,n2);
            
        }
        
        return ans;
        
    }
};