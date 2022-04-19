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
     TreeNode* fir=NULL;
     TreeNode* sec=NULL;
     TreeNode* prev=NULL;
    void findinviolance(TreeNode* root){
        
        if(!root) return ;
        
        findinviolance(root->left);
        if(prev and prev->val > root->val and fir==NULL){
            fir=prev; 
            sec=root; 
        }else if(prev and prev->val > root->val){
            sec=root; 
        } 
        prev=root;
        findinviolance(root->right);
    }
    void recoverTree(TreeNode* root) { 
       findinviolance(root);
       swap(fir->val,sec->val);
       
      return ;
    }
};