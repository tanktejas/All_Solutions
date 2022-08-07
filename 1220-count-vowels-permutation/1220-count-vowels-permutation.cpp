class Solution {
public:
    int mod=1000000007;
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        if(n==1) return 5;
        else if(n==2) return 10;
        
        dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;
        
        for(int i=2;i<=n;i++)
        {  
            dp[i][0]=((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][4])%mod;
            dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
            dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
            dp[i][3]=(dp[i-1][2])%mod;
            dp[i][4]=(dp[i-1][2]+dp[i-1][3])%mod;
             
        }
        
        return (((dp[n][0]+dp[n][1])%mod+(dp[n][2]+dp[n][3])%mod)%mod+dp[n][4])%mod;
    }  
};