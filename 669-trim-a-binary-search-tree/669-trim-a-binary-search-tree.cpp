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
    TreeNode* find(TreeNode* root,int l,int h){
      if(root==NULL) return root;
      if(root->val >=l and root->val <= h){
            return root;
          }
         if(root->val <l) 
             return find(root->right,l,h);
         else
             return find(root->left,l,h);
        
      } 
    void reml(TreeNode* ans,int l){
         TreeNode* temp=ans;
         while(temp){  
             if(temp->left){ 
               TreeNode* curr=temp; 
                 if(temp->left->val<l){ 
                   temp=temp->left->right;
                     while(temp and temp->val<l)
                         temp=temp->right;
                   curr->left=temp; 
                 }else{
                     temp=temp->left;
                 } 
             }else{ 
                    temp=temp->right; 
             }
         }   
    } 
      void remr(TreeNode* ans,int r){
         TreeNode* temp=ans;
         while(temp){ 
              if(temp->right){ 
               TreeNode* curr=temp; 
                 if(temp->right->val>r){ 
                   temp=temp->right->left;
                     while(temp and temp->val>r)
                         temp=temp->left;
                   curr->right=temp; 
                 }else{
                     temp=temp->right;
                 } 
             }else{ 
                    temp=temp->left; 
             }
         } 
    }
    TreeNode* trimBST(TreeNode* root, int l, int r) {
        TreeNode* ans=find(root,l,r); 
           reml(ans,l); 
           remr(ans,r); 
        
        return ans;
    }
};