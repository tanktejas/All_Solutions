class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>suf(n+2,0);
        vector<int>pre(n+1,0);
        
        
        for(int i=1;i<=n;i++)
        {
            pre[i]+=pre[i-1];
            pre[i]+=(nums[i-1]==0);
        }
         
        for(int i=n;i>0;i--)
        {    
            suf[i]+=suf[i+1];
            suf[i]+=(nums[i-1]==1);
        }
        
        int msum=0;
        vector<int>ans;
        
        for(int i=0;i<=n;i++)
        {
            int cs=pre[i]+suf[i+1];
             
            if(cs > msum){
                msum=cs; 
            } 
            
        }
        
        for(int i=0;i<=n;i++)
        {
            int cs=pre[i]+suf[i+1];
             
            if(cs == msum){
                ans.push_back(i);
            } 
            
        }
        
        return ans;
    }
};