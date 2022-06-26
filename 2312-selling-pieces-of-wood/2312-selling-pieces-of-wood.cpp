class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& pr) {
        vector<vector<long long int>>dp(201,vector<long long>(201,0));
         
        for(int i=0;i<pr.size();i++){
            dp[pr[i][0]][pr[i][1]]=pr[i][2];
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                for(int k=1;k<i;k++){
                    dp[i][j]=max(dp[i][j],dp[i-k][j] + dp[k][j]);
                }
                
                for(int k=1;k<j;k++){
                    dp[i][j]=max(dp[i][j],dp[i][j-k] + dp[i][k]);
                }
                
            }
        }
        
        return dp[m][n];
    }
};   