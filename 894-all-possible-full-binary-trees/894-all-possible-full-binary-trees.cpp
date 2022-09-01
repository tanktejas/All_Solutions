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
    vector<TreeNode*>ans;
    int nn;
    
    vector<TreeNode*> find(int f,int l)
    {
     
        if(f==l){
            TreeNode* root=new TreeNode(0);
            return {root};
        }  
        
        vector<TreeNode*>temp;
        
        for(int i=f;i<=l;i++)
        {
          if((i-f)%2!=0 and (l-i)%2!=0){
               
              vector<TreeNode*> left=find(f,i-1);
              vector<TreeNode*> right=find(i+1,l);
             
              for(auto ele:left)
              {
                  for(auto ele1:right)
                  {  
                      TreeNode* root=new TreeNode(0);
                      root->left=ele;
                      root->right=ele1;
                      
                      temp.push_back(root);
                  }
              }
              
          }  
            
        }
        
        return temp;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        nn=n;
        return find(1,n);
         
    }
};