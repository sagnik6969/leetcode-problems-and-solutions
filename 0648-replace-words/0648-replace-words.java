class Node {
    String word;
    Node[] next = new Node[26];

    public Node(){
        word = null;
        for(int i = 0 ; i < 26 ; i++){
            next[i] = null;
        }
    }

    public Node(String word){
        this.word = word;
        for(int i = 0 ; i < 26 ; i++){
            next[i] = null;
        }
    }
}

class Trie {
    Node root;
    public Trie(){
        this.root = new Node();
    }

    private void insertWordPrivate(String word,int idx,Node curr){
        if(idx == word.length()){
            curr.word = word;
            return;
        }

        Node next = null;

        if(curr.next[word.charAt(idx) - 'a'] != null) 
            next = curr.next[word.charAt(idx) - 'a'];
        else {
            next = new Node();
            curr.next[word.charAt(idx) - 'a'] = next;
        }

        this.insertWordPrivate(word,idx+1,next);
    }

    public void insertWord(String word){
        this.insertWordPrivate(word,0,this.root);
    }

    private String getRootPrivate(String word,int idx,Node curr){
        if(curr == null || idx == word.length()) return word;
        if(curr.word != null) return curr.word;
        return this.getRootPrivate(word,idx + 1,curr.next[word.charAt(idx) - 'a']);
    }

    public String getRoot(String word){
       return getRootPrivate(word,0,root);
    }
}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {

        Trie trie = new Trie();

        for(String word:dictionary){
            trie.insertWord(word);
        }

        String[] arr = sentence.split(" ");
        StringBuilder ans = new StringBuilder("");

        for(String word:arr){
            String root = trie.getRoot(word);
            ans.append(root);
            ans.append(' ');
        }
         ans.deleteCharAt(ans.length() - 1);

        return ans.toString();
        
    }
}