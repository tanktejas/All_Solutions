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
    void findsum(TreeNode* root,int &sum){
        if(!root){
            return ;
        } 
        sum+=root->val;
        findsum(root->left,sum);
        findsum(root->right,sum);
    }
    void update(TreeNode* root,int &sum){
      if(!root) return ;
        
        update(root->left,sum);
        int temp=root->val;
        root->val=sum;  
        sum=sum-temp;    
        update(root->right,sum);
         
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
            
        findsum(root,sum); 
        
        update(root,sum);
        
        return root;
    }
};