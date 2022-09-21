class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int qs=q.size();
        
        vector<int>ans(qs);
        int cs=0;
        
        for(int i=0;i<n;i++)
        { 
            cs+=((nums[i]%2)==0 ? nums[i] : 0);
        } 
        
        for(int i=0;i<qs;i++)
        {
            int idx=q[i][1];
            int val=q[i][0];
            int yy=nums[idx];
            
            if(yy%2 == 0)
            {
                nums[idx]+=val;
                if(val%2 == 0){
                    cs+=val;  
                }else{
                    cs-=yy;
                }
            }else{
                nums[idx]+=val;
                if(val%2 != 0){
                    cs+=nums[idx];
                }  
            }
            ans[i]=cs;
        }
        
        return ans;
        
    }
};