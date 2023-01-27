
class node{
    public:
    node* next[26];
    bool is_terminal;
    node(){
        for(int i = 0 ; i < 26 ; i++) next[i] =  NULL;
        is_terminal = false;
    }
};

bool find(string &word,int idx,node* root,node* original_root){

    if(root == NULL) return false;
    
    if(idx == word.size()){
        return root -> is_terminal;
    }

    int next_idx = word[idx] - 'a';

    node* next;

    return find(word,idx+1,root -> next[next_idx],original_root)
           || (root -> is_terminal && find(word,idx+1,original_root ->                   next[next_idx], original_root));

}

void inseret(string &word,int idx,node* root){
    
    if(idx == word.size()){
        
        root -> is_terminal = true;
        return;
    }

    int next_idx = word[idx] - 'a';

    node* next;

    if(root -> next[next_idx] != NULL) next = root -> next[next_idx];
    else {
        root -> next[next_idx] = new node();
        next = root -> next[next_idx];
    }

    return inseret(word,idx+1,next);

}


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        sort(words.begin(),words.end(),[&](string &s1,string &s2){
            return s1.size() < s2.size();
        });
        node* root = new node();
        vector<string> ans;
        for(auto i:words){
            if(find(i,0,root,root)) ans.push_back(i);
            //else{
                inseret(i,0,root);
            //} 
        }
        // cout << find_or_inseret(words[0],0,root) << endl;
        // cout << find_or_inseret(words[0],0,root) << endl;
        for(auto i:words) cout << i << " ";

        return ans;
    }
};