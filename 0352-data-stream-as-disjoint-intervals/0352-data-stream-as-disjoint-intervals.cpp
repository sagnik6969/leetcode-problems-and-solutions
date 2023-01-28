class SummaryRanges {
public:
    
  
    map<int,int> begin_to_end;
    map<int,int> end_to_begin;
    set<int> s;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {

        if(s.find(value) == s.end()) s.insert(value);
        else return; 
       
        int begin = value;
        int end = value;
        
        if(begin_to_end.find(value+1) != begin_to_end.end()){
            end = begin_to_end[value+1];
            end_to_begin.erase(end);
            begin_to_end.erase(value+1); 
        }
        
        if(end_to_begin.find(value-1) != end_to_begin.end()){
            begin = end_to_begin[value-1];
            begin_to_end.erase(begin);
            end_to_begin.erase(value-1);
        }
        
        begin_to_end[begin] = end;
        end_to_begin[end] = begin;
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> v;
        
        for(auto i:begin_to_end) v.push_back({i.first,i.second});
        
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */