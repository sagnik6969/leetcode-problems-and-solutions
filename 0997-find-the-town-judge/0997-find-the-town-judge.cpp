class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> arr1(n+1,0);
        vector<int> arr2(n+1,0);

        for(auto &i:trust){ 
            arr1[i[1]]++;
            arr2[i[0]]++;
        }

        for(int i = 1 ; i <= n ; i++){
            if(arr1[i] == n-1 && arr2[i] == 0) return i;
        }
        return -1;
    }
};