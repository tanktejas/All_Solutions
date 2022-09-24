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
    int mlen=0;
    
    int find(TreeNode* root,long long tt)
    {     
        if(!root) return 0;
        
        int lef=0,rig=0;
        
        if(root->val==tt)
        {
            lef=find(root->left,tt);
            rig=find(root->right,tt);
        }
        
        if(root->val!=tt) return 0;
        else 
         return 1+max(lef,rig);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
        {  
            return 0;
        }
        long long sum=0; 
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        bool same=0;
         
        while(q.size()!=1)
        {
            if(q.front()==NULL)
            {
                q.pop();
                q.push(NULL);
            }
            TreeNode* tt=q.front();
            q.pop();  
            int lef=0,rig=0;
             
            lef=find(tt->left,tt->val);  
            rig=find(tt->right,tt->val);
            
            mlen=max(mlen,lef+rig);  
            
            if(tt->left) q.push(tt->left);
            if(tt->right) q.push(tt->right);
            
        }
        
        return mlen;
    }
};