class Solution {
public:
    
    int get_total(vector<int>& energy, int k,int start){
        
        int sum = 0;
        
        for(int i = start ; i < energy.size() ; i += k ){
            if(sum < 0) sum = 0;
            sum += energy[i];
        }
        
        return sum;
        
    }
    
    int maximumEnergy(vector<int>& energy, int k) {
        
        int ans = INT_MIN;
        
        for(int i = 0 ; i <= k-1 ; i++){
            ans = max(ans,get_total(energy, k, i));
        }
        
        return ans;
    }
};