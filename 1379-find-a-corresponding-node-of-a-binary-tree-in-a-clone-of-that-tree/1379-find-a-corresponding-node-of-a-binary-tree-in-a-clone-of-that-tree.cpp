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
    
    TreeNode* find(TreeNode* r,TreeNode* c,TreeNode* ta){
           if(!r) return NULL;
          if(r->val==ta->val) return c;
           TreeNode* lef=find(r->left,c->left,ta);
          if(lef){
              return lef;
          }
          TreeNode* righ=find(r->right,c->right,ta);
          if(righ){
              return righ;
          }
       return NULL;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return find(original,cloned,target);
    }
};