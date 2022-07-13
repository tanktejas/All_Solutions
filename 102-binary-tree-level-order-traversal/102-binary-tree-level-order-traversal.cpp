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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>tm;
       
        if(!root) return {};
       
        ans.push_back({root->val});
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()!=1){
            if(q.front()==NULL){
                ans.push_back(tm);
                q.pop();  
                tm.clear();
                q.push(NULL);
            }
            auto tt=q.front();
            q.pop();
            
            if(tt->left){
                q.push(tt->left);
                tm.push_back(tt->left->val);
            }
            
            if(tt->right){
                q.push(tt->right);
                tm.push_back(tt->right->val);
            }
            
        }
        
        return ans;
    }
};