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
    
    int ans=0;
    int target;
    
    void find(TreeNode* root,long long sum)
    {     
       
        if((sum+root->val) == target) {  
            ans++;
        }
        
        if(!root->left and !root->right)
        {  
             return ;
        }
           
        if(root->left)
           find(root->left,sum+root->val);
        if(root->right)
           find(root->right,sum+root->val);
        
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {  
            return 0;
        }
        long long sum=0;
        target=targetSum;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()!=1)
        {
            if(q.front()==NULL)
            {
                q.pop();
                q.push(NULL);
            }
            TreeNode* tt=q.front();
            q.pop(); 
            
            find(tt,0);  
              
            if(tt->left) q.push(tt->left);
            if(tt->right) q.push(tt->right);
            
        }
        
        return ans;
    }
};