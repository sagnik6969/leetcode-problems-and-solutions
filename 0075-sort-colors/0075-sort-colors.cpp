class Solution {
public:
    void sortColors(vector<int>& nums) {
         int i = 0;
        int j = nums.size() - 1;
        
        for(int k = 0 ; k < nums.size() && k  <= j ; k++){

            
            
            if(nums[k] == 0){ 
                swap(nums[i++],nums[k]); 
            }
            else if(nums[k] == 2){ 
                swap(nums[j--],nums[k]);
                k--;
            }

            
            
        }
    }
};