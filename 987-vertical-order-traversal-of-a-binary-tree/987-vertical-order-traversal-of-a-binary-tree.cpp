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
    map<int,vector<int>>m;
    int mincol;
    int maxrow;
    int maxcol;
    map<pair<int,int>,vector<int>>mp;
    
    void tra(TreeNode* root,int ele,int row,int col){
        
        if(!root) return ;
        
        mincol=min(mincol,col);
        maxrow=max(maxrow,row);
        maxcol=max(maxcol,col);
        
        mp[{row,col}].push_back(root->val);
         
        tra(root->left,ele-1,row+1,col-1);
        tra(root->right,ele+1,row+1,col+1);
        
        return ;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>ans;
        
        mincol=INT_MAX;
        maxcol=INT_MIN;
        maxrow=INT_MIN;
        
        tra(root,0,0,0);
       
        for(auto ele:m)
        {  
            ans.push_back(ele.second);  
        }
        
        for(int i=0;i<=maxrow;i++)
        {
            for(int j=mincol;j<=maxcol;j++)
            { 
                sort(mp[{i,j}].begin(),mp[{i,j}].end());
            }
        }
        
        
        for(int i=mincol;i<=maxcol;i++)
        {
            vector<int>temp;
            for(int j=0;j<=maxrow;j++)
            {
                for(int ele:mp[{j,i}])
                {
                    temp.push_back(ele);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};