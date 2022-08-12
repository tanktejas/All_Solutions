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
    
    TreeNode* find(TreeNode* root,int p,int q){

        if(!root) return NULL;
        
        if(root->val == p or root->val == q) return root;
        
        if(root->val > p and root->val < q){  
            return root;
        }
        
       TreeNode* lef = find(root->left,p,q);
       TreeNode* rig = find(root->right,p,q);
        
       if(lef) return lef;
       if(rig) return rig;
        
        return NULL;
       
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) swap(p,q);
        
        return find(root,p->val,q->val);
    }
};