class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,pair<int,int>>>q;
        vector<int>ans;
        int n=nums.size();
        q.push(make_pair(0,make_pair(0,nums[0][0]))); 
        
        while(!q.empty())
        {
            pair<int,pair<int,int>>p=q.front();
            q.pop();
            
            ans.push_back(p.second.second);
            
            int x=p.first;
            int y=p.second.first;
            
            if((x+1) < n and ((y) < nums[x+1].size()) and nums[x+1][y]!=-1)
            {  
                q.push(make_pair(x+1,make_pair(y,nums[x+1][y]))); 
                nums[x+1][y]=-1;
            }
            
            if((y+1) < nums[x].size() and nums[x][y+1]!=-1)
            {
                q.push(make_pair(x,make_pair(y+1,nums[x][y+1]))); 
                nums[x][y+1]=-1;
            }
            
        }
        
        return ans;
    }
};