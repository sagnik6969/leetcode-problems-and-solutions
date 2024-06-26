class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int low = 0;
        int high = height.size() - 1;
        
        int ans = 0;
        
        while(low < high){
            
            int h = min(height[low],height[high]);
            
            ans = max(ans,(high - low) * h);
            
            if(height[low] > height[high]) high--;
            else low++;
            
        }
        
        return ans;
        
    }
};