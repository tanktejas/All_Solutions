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
    vector<int>v;
    int ans;
    
    void find(TreeNode* root)
    {
        if(!root) return ;
        
        if(!root->left and !root->right)
        {
            int odd=0;
            v[root->val]++;
            for(int i=1;i<=9;i++)
            {
                if(v[i]%2 != 0) odd++;
            }
            v[root->val]--;
            ans+=(odd<2);
            
            return ;
        }
        
       v[root->val]++;
       find(root->left);
       find(root->right);
       v[root->val]--;
        
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        v.resize(10,0);
        ans=0;
        find(root);
        
        return ans;
    }
};