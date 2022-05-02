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
    int dolevel(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum=root->val;
        while(q.size()>1){
            if(q.front()==NULL){
                q.pop();
                q.push(NULL);
                sum=0;
            }
            auto a=q.front();
            q.pop();
            sum+=a->val;
            if(a->left){
                q.push(a->left);
            }
            if(a->right){
                q.push(a->right);
            }
        }
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
       return  dolevel(root);
    }
};