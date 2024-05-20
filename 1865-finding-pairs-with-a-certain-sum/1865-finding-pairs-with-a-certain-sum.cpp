class FindSumPairs {
public:
    vector<int> v1,v2;
    unordered_map<int,int> m;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;

        for(auto i:v2) m[i]++;
        
    }
    
    void add(int index, int val) {

        if(m[v2[index]] == 1) m.erase(v2[index]);
        else m[v2[index]]--;

        v2[index] += val;

        m[v2[index]]++;
        
    }
    
    int count(int tot) {
        int ans = 0;

        for(auto i:v1){
            if(m.find(tot - i) != m.end()) ans += m[tot - i];
        }
        return ans;    
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */