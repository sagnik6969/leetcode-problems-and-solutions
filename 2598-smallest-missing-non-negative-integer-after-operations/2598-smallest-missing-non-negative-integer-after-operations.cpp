class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> m;
        for(int i = 0 ; i < value ; i++) m[i] = 0;
        for(auto i:nums){
        if(i < 0){
            int curr = i % value;
            if(curr < 0) curr += value;
             m[curr]++; 
        }   
        else m[i % value]++;
        } 

        int mn = (nums[0] % value);

        for(auto i:m){
            if(m[mn] > i.second) mn = i.first;
            else if(m[mn] == i.second && i.first < mn) mn = i.first; 
        }

        //cout << mn << endl;

        return m[mn] * value + mn;
        
    }
};