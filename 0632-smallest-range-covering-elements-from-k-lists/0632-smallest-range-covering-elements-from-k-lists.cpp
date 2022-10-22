class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        int maxi=0;
        
        int k=nums.size();
        
        for(int i=0;i<k;i++)
        {
            q.push({nums[i][0],i,0});
            maxi=max(maxi,nums[i][0]);
        }
        
        int mini=INT_MAX;
        int l=-1,r=-1;
        
        while(!q.empty())
        {
            auto ele=q.top();
            q.pop();
            
            
            int siz=nums[ele[1]].size();
            
           
            
            if((maxi - ele[0]) < mini)
            { 
                l=ele[0];
                r=maxi;
                mini=maxi-ele[0];
            }
            
            if((ele[2]+1) < siz)
            {  
                maxi=max(maxi,nums[ele[1]][ele[2]+1]);
                q.push({nums[ele[1]][ele[2]+1],ele[1],ele[2]+1});
            }else{
                break;
            }   
            
        }
        
        return {l,r};
    }
};