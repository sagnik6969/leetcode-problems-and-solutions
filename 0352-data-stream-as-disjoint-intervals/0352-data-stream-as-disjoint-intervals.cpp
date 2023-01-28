class SummaryRanges {
public:
    
   
    vector<vector<int>> v;
    set<int> s;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        
        s.insert(value);
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> v;
        int prev = -7;
        
        for(auto i:s){
            if(i == prev + 1) v.back()[1] = i;
            else v.push_back({i,i});
            prev = i;
        }
        
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */