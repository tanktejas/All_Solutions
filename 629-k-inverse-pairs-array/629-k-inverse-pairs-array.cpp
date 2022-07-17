class Solution {
public:
    int dp[1001][1001];
    int mod=1000000007;
    
    int find(int n,int k){
        if(n==0) return 0;
        if(k==0) return 1;
        int ans=0;
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        for(int i=0;i<=min(k,n-1);i++){
            ans=(ans +  find(n-1,k-i))%mod;     
        }    
        
        return dp[n][k]=ans;
    }
    
    int kInversePairs(int n, int k) {
        memset(dp,0,sizeof(dp));
        int ans=0; 
        //  ans=find(n,k);
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){ 
                if(j==0) dp[i][j]=1;  
                else{
                    int val=(((dp[i-1][j] + mod)%mod - ((j-i)>=0 ? dp[i-1][j-i] : 0)%mod))%mod;
                    dp[i][j]=(dp[i][j-1]  + val)%mod;
                    
//                     int val = (dp[i - 1][j] + mod - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % mod;
//                     dp[i][j] = (dp[i][j - 1] + val) % mod;
                    
                }   
            
            }
        }
         
        return ((dp[n][k] + mod) - ((k-1)>=0 ? dp[n][k-1] : 0))%mod;
        
        // return ans;
    }
    
};