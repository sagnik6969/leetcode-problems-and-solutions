class Solution {
public:
    
    
    bool f(int n,int sum){

        if(n == sum) return true;
        if(n < 0) return false;
        if(sum == 0 && n != 0) return false;
        
        bool ans = false;
        
        long long s = 0;
        int cnt = 1;
        
        while(sum != 0){
            
            s += (sum % 10) * cnt;
            cnt *= 10;
            sum /= 10;

            if(f(n-s,sum)) return true;
            
        }
    
        return false;
       
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