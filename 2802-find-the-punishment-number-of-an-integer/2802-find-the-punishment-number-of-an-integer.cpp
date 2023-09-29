class Solution {
public:
    
    unordered_map<long long,bool> dp;
    
    bool f(long long n,long long sum){
        //cout << n << " " << sum << endl;
         if(n == sum) return true;
        if(n < 0) return false;
        if(sum == 0 && n != 0) return false;
       
        
        if(dp.count((sum << 10) + n)) return dp[(sum << 10) + n];
        
        bool ans = false;
        
        long long or_n = n;
        long long or_sum = sum;
        
        long long s = 0;
        int cnt = 1;
        
        while(sum != 0){
            
            s += (sum % 10) * cnt;
            cnt *= 10;
            sum /= 10;
            
            //if(or_n == 10 && or_sum == 22) cout << "test " <<  n << " " << s << " " << sum << endl;
            
            if(f(n-s,sum)){
                ans = true;
                break;
            }
        }
        
        
        dp[(or_sum << 10) + or_n] = ans; 
        return ans;
       
    }
    
    
    int punishmentNumber(int n) {
        
        //dp = unordered_map<long long,bool>();
        
        int ans = 0;
        
       // cout << f(15,225) << endl;
        
        for(int i = 1 ; i <= n ; i++){
            if(f(i,i * i)){
            
             //   cout << i << endl;
                ans += i*i;
            }
        }
        
        return ans;
        
    }
};