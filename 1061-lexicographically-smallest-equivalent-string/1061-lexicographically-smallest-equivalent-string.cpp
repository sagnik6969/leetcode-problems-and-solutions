class Solution {
public:

    int find_parent(int child,vector<int> &parent,vector<int> &size){
           
           if(child == parent[child]) return child;

           parent[child] = find_parent(parent[child],parent,size);

           return parent[child];

    }
    
    void unite(int n1,int n2,vector<int> &parent,vector<int> &size){
            
            int p1 = find_parent(n1,parent,size);
            int p2 = find_parent(n2,parent,size);

            if(p1 == p2) return;

            if(size[p1] < size[p2]) swap(p1,p2);
            
            size[p1] += size[p2];
            parent[p2] = p1;

    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        vector<int> parent(26);
        vector<int> size(26);
        vector<int> best(26);

        for(int i = 0 ; i < 26 ; i++){
            parent[i] = i;
            size[i] = 1;
            best[i] = i;
        }

        for(int i = 0 ; i < s1.size() ; i++){
            
            unite(s1[i] - 'a',s2[i] - 'a',parent,size);
            

        }


        for(int i = 0 ; i < 26 ; i++){
            
            int p = find_parent(i,parent,size);

            best[p] = min(best[p],i);
        }


        for(auto &i:baseStr){ 
            
            i = 'a' + best[find_parent(i-'a',parent,size)];
        }

        return baseStr;
        
    }
};