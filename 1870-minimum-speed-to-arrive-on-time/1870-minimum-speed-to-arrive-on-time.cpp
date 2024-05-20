class Solution {
public:

    int calc_high(vector<int>& dist, double hour){
        hour -= (dist.size() - 1);
        if(hour <= 0) return INT_MIN;

        return ceil(dist.back() / hour);
    }
 
    int minSpeedOnTime(vector<int>& dist, double hour) {

        int low = 1;
        int high = *max_element(dist.begin(), dist.end());
        high = max(high,calc_high(dist,hour));

        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            double total_time = 0;

            for(int i = 0 ; i < dist.size() ; i++){
                if(i == dist.size() - 1) total_time += ((double)dist[i]) / ((double)mid);
                else if(dist[i] % mid == 0) total_time += dist[i] / mid;
                else total_time += dist[i] / mid + 1;

              //  cout << mid << endl;
            }

            if(total_time <= hour){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;

            cout << mid << " " << total_time << endl;
        }

        return ans;
        
    }
};