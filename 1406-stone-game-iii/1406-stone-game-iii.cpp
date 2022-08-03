class Solution {
public:
    vector<vector<int>>dp;
     
    string stoneGameIII(vector<int>& sv) {
        int n=sv.size();   
        dp.resize(n+9,vector<int>(4,0));
        
        dp[n-1][1]=sv[n-1];
        dp[n-1][2]=sv[n-1];
        dp[n-1][3]=sv[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            int maxi=INT_MIN;
            for(int j=1;j<=3;j++)
            {
                int sum=0;
                for(int k=0;k<j;k++)
                {
                    if((i+k)<n) sum+=sv[i+k];
                } 
                   int yy=max({dp[i+j][1],dp[i+j][2],dp[i+j][3]}); 
                     dp[i][j]=max(maxi,sum - yy); 
            }
            
        }
        
        
        if(dp[0][1]>0 or dp[0][2]>0 or dp[0][3]>0) return "Alice";
        else if(dp[0][1]==0 or dp[0][2]==0 or dp[0][3]==0) return "Tie";
        else return "Bob";
         
    }
};