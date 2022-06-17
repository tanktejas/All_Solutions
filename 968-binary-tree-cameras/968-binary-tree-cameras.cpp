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
    int find(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left and !root->right){
            return -1;                                                   
        }
        
        int lef=find(root->left);
        int righ=find(root->right);
        
        cout<<lef<<" "<<righ<<endl;
        
        if(lef==0 and righ==0){
            return -1;
        }
        if(lef==1 and righ==1){
            return 0;
        } 
      
         if((lef==-1 or righ==-1)){
            ans++;
            return 1;
        }
        
        
        return 0;
        
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root->left and !root->right) return 1;
        if(find(root)==-1) return ans+1;
        return ans;
    }
};