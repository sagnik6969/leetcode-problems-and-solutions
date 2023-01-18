class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {

        int sign = 1;

        if(numerator < 0 && denominator > 0) sign = -1;
        else if(numerator > 0 && denominator < 0) sign = -1;
        
        numerator = abs(numerator);
        denominator = abs(denominator);

        
        string integer;
        
        string decimal = "";
        
        if(sign == -1) integer = "-";

        integer += to_string((numerator/denominator));
        
        numerator %= denominator;
        
        if(numerator == 0) return integer;
        
        map<int,int> prev;
        
        while(numerator != 0 && prev.find(numerator) == prev.end()){
            
           // cout << numerator << " ";
            
            prev[numerator] = decimal.size();
            
            numerator *= 10;
            
            while(numerator < denominator){
                decimal += '0';
                
                numerator *= 10;
            }
            
            decimal += to_string(numerator/denominator);
            
             numerator %= denominator;

        }
        
        if(numerator == 0) return integer + "." + decimal;

        //cout << decimal << " " << prev[numerator] <<   endl ;
        
        decimal.insert(decimal.begin()+prev[numerator],'(');

        //cout << decimal << endl ;

        return integer + "." + decimal + ")";
    
    }
};