class Solution {
public:

   void rec(vector<string>& words, vector<int>& cnt, vector<int>& score,int idx,int curr_score,int &max_score){
      if(words.size() == idx){
        max_score = max(max_score,curr_score);
        return;
      }

      rec(words,cnt,score,idx+1,curr_score,max_score);

      vector<int> curr_cnt(26,0);

    


      for(auto i:words[idx]){
        cnt[i-'a']--;
        curr_cnt[i-'a']++; 
      }

      bool flag = 0;

      for(auto i:cnt){
        if(i < 0){
            flag = 1;
            break;
        }
      }

      
         
   
   if(flag == 0){
    for(auto i:words[idx]) curr_score += score[i - 'a'];
    rec(words,cnt,score,idx+1,curr_score,max_score);
   }

    for(int i = 0 ; i < 26 ; i++) cnt[i] += curr_cnt[i];

   }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        vector<int> cnt(26,0);

        for(auto i:letters) cnt[i-'a']++;

        int max_score = 0;

        rec(words,cnt,score,0,0,max_score);
        
        return max_score;
        
    }
};