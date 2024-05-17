/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

     bool f(TreeNode* root, int target){

        if(root == nullptr) return false;
        
       

        if(f(root -> left,target)){
            root -> left = nullptr;
        }   

        if(f(root -> right, target)){
          root -> right = nullptr;  
        }

         if(root -> left == nullptr && root -> right == nullptr){
            if(root -> val == target) return true;
        }
     
            return false;
     }
     
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(f(root,target)) return nullptr;

        return root;

        
    }
};