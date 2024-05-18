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
   int f(TreeNode* root,int &ans){
      if(root == nullptr) return 0;
      if(root -> left == nullptr && root -> right == nullptr){
        return root -> val - 1;
      }

      int n1 = f(root -> right,ans);
      int n2 = f(root -> left, ans);

      ans += abs(n1) + abs(n2);

      return n1 + n2;

   }
    int distributeCoins(TreeNode* root) {

        int ans = 0;

        f(root,ans);

        return ans;
        
    }
};