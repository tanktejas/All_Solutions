class Solution {
public:
    int min(long long i,int j)
    {
        if(i<j) return i;
        return j;
    }
    
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<long long>>dp(3,vector<long long>(n,0));
        
        dp[0][0]=nums[0];
        dp[1][0]=1ll*2*INT_MAX;
        dp[2][0]=1ll*2*INT_MAX;
        for(int i=1;i<n;i++)
        {
            dp[0][i]=min(dp[0][i-1],nums[i]);
            dp[1][i]=dp[1][i-1];
            dp[2][i]=dp[2][i-1];
            
            if(dp[0][i-1] < nums[i])
            {
                dp[1][i]=min(dp[1][i],nums[i]);
            }
            
            if(dp[1][i-1] < nums[i])
            { 
                dp[2][i]=min(dp[2][i],nums[i]);
            }  
        }   
        
       return dp[2][n-1]!=1ll*2*INT_MAX;
        
    }
    
};