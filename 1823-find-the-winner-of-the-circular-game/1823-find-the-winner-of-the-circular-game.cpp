class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> q;
        
        for(int i = 1 ; i <= n ; i++){
            q.push(i);
        }
        
        while(q.size() != 1){
            
           // int curr = k % q.size();
            
           // cout << curr << endl;
            
            for(int i = 0 ; i < k-1 ; i++){
                int c = q.front();
                q.pop();
                q.push(c);
            }
            
            //cout << q.front() << endl;
            
            q.pop();
            
        }
        
        return q.front();
        
    }
};