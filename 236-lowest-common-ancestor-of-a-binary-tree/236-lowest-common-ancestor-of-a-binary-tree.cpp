/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca;
    
    bool find(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root) return 0;
        
        if(!root->left and !root->right) return (p->val==root->val or q->val==root->val);
        
       bool l=find(root->left,p,q);
       bool r=find(root->right,p,q);
        
        if(l and r){
            lca=root;
            return 0;
        }else if((l and (root->val==p->val or root->val==q->val)) or (r and (root->val==p->val or root->val==q->val))){
            lca=root;
            return 0;
        }  
        if(root->val==5){
            cout<<l<<' '<<r;
        }
        
        if(root->val==p->val or root->val==q->val) return 1;
        
        return l or r;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            find(root,p,q);
        return lca;
    }
};