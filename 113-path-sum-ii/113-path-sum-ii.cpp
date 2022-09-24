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
    void find(TreeNode* root,int &sum,int ts,vector<int> &temp,vector<vector<int>>&v){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL and root->right==NULL){
            if(sum+root->val==ts){
                temp.push_back(root->val);
                v.push_back(temp);
                temp.pop_back();
            }   
            return ;
        }
        sum+=root->val;
        temp.push_back(root->val);
        find(root->left,sum,ts,temp,v);
         
        find(root->right,sum,ts,temp,v);
         sum-=root->val; 
        temp.pop_back();  
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       int sum=0;
        vector<vector<int>> v;
        vector<int>temp;
         
    
        find(root,sum,targetSum,temp,v);
        
        return v;
    }
};