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
    vector<int> dolevel(TreeNode* root){
        
       queue<TreeNode*>q;
        int prv=0;
        vector<int>ans;
        if(!root) return {};
        q.push(root);
        q.push(NULL);  
        while(q.size()>1){
             if(q.front()==NULL){
                 q.pop();
                 q.push(NULL);
                 ans.push_back(prv);
                 cout<<q.size();
             }
            auto ele=q.front();
            q.pop();
            prv=ele->val;
            if(ele->left){
                q.push(ele->left);
            }
             if(ele->right){
                q.push(ele->right);
            }
            
        }
        ans.push_back(prv);
        return ans;
    }
    
    vector<int> rightSideView(TreeNode* root) {
       return dolevel(root);
    }
};