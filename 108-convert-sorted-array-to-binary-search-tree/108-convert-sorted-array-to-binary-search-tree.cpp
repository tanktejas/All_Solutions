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
    TreeNode* find(int f,int s){
        if(f>s) return NULL;
        if(f==s) return new TreeNode(v[s]);
        
        int mid=(f+s)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=find(f,mid-1);
        root->right=find(mid+1,s);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         v=nums;
         return find(0,nums.size()-1);
    }
};