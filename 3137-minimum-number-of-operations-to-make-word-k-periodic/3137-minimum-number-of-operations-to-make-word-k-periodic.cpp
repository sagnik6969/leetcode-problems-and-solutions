class node {
    
    
    public:
    node* next[26];
    int count;
    node(){
        for(int i = 0 ; i < 26 ; i++){
            next[i] = NULL;
        }
        
        count = 0;
    }
    
};


int mx = 0;

void insert(node* curr,string &word,int start,int end){
    
    if(start > end){
        curr -> count++;
        mx = max(mx,curr -> count);
        return;
    }
    
    node* next = curr -> next[word[start] - 'a'];
    if(next == NULL){
        next = new node();
        curr -> next[word[start] - 'a'] = next;
    }
    
    insert(next,word,start+1,end);
}



class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        
        node* root = new node();
        mx = 0;
        for(int i = 0 ; i < word.size() ; i+=k){
            insert(root,word,i,i+k-1);
        }
        
        return word.size()/k - mx;
        
    }
};