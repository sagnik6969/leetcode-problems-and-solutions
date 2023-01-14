class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int m = nums1.size();
        int n = nums2.size();
        int size = (m + n + 1) / 2; // no of elements <= of median in the sorted array
        
        
        int low = max(0,size - n);
        int high = min(m,size);
        
        while(low <= high){
            
            int cut1 = (low + high) / 2; 
            int cut2 = size - cut1;
           
            int l1 = cut1 - 1 < 0 ? INT_MIN : nums1[cut1 - 1];
            int r1 = cut1 >= m ? INT_MAX : nums1[cut1];
            int l2 = cut2 - 1 < 0 ? INT_MIN : nums2[cut2 - 1];
            int r2 = cut2 >= n ? INT_MAX : nums2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                
                if((m + n) % 2 != 0) return max(l1,l2);
              
                return (max(l1,l2) + min(r1,r2))/2.0;
            }
            else if(r2 < l1) high = cut1 - 1;
            else low = cut1 + 1;
            
        }
        
        return 0;
    }
};