class Solution {
public:
        
    bool f(int n,int sum){
        if(n == sum) return true;
        if(n < 0) return false;
        if(sum == 0 && n != 0) return false;
        int s = 0;
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
        
        int ans = 0;
        
        for(int i = 1 ; i <= n ; i++){
            if(f(i,i * i)) ans += i*i;
        }
        
        return ans;
        
    }
};