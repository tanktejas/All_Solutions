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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        
        q.push(root);
        q.push(NULL);
        
        double sum=0;
        double cnt=0;
        vector<double>ans;
        
        while(q.size()!=1)
        {
            if(q.front()==NULL)
            {
                double f=(sum/cnt);
                sum=0;
                cnt=0;
                ans.push_back(f);
                q.pop();
                q.push(NULL);
            }
            
            TreeNode* tt=q.front();
            q.pop();
            sum+=tt->val;
            cnt++;
            
            if(tt->left)
            {
                q.push(tt->left);
            }
            if(tt->right)
            {
                q.push(tt->right);
            }
        }
        
         double f=(sum/cnt);
         ans.push_back(f);
        
        return ans;
    }
};