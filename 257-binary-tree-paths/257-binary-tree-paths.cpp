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
    void find(TreeNode* root,string curr,vector<string> & ans){
        if(!root) return ;
        
        if(!root->left and !root->right){
            string currans=curr;
            currans+=to_string(root->val);
            ans.push_back(currans);
            return ;
        }
        
        string tmp="";
        tmp+=to_string(root->val);  
        find(root->left,curr+tmp+"->",ans);
        find(root->right,curr+tmp+"->",ans);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans; 
      
        find(root,"",ans);
        return ans;
    }  
};