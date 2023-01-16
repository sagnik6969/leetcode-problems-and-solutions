
// https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations
class Solution {
public:
    int divide(long long dividend,long divisor) {
          
          int sign = 1;

          if(dividend >= 0 && divisor < 0) sign = -1;
          if(dividend < 0 && divisor > 0) sign = -1;

          dividend = abs(dividend);
          divisor = abs(divisor);
          
          
          long long ans = 0;

          while(dividend >= divisor){
              
          long long curr = divisor;
          long long t = 0;

          while(curr <= dividend){
              curr <<= 1;
              t++;
          }

          t--;
          curr >>= 1;

          ans += ((long long)1 << t);
          dividend -= curr;
          
          }

        
        ans *= sign;

          if(ans > INT_MAX) return INT_MAX;
          if(ans < INT_MIN) return INT_MIN;

          return ans;

    }
};