class Solution {
public:
    vector<long long>dp;
    
    long long find(int st,vector<vector<int>> &qu){
        if(st>=qu.size()) return 0;
        
        if(dp[st]!=-1) return dp[st];
        
        return dp[st]=max(qu[st][0] + find(st+qu[st][1]+1,qu),find(st+1,qu));
    }
    
    long long mostPoints(vector<vector<int>>& qu) {
         int n=qu.size();
         dp.resize(n+1,-1); 
        
         for(int i=n-1;i>=0;i--)
         {  
              dp[i]=qu[i][0]; 
              if((i+qu[i][1]+1) < n){
                  dp[i]=max(dp[i],qu[i][0] + dp[i+qu[i][1]+1]);
              }  
             
              if(i!=n-1) dp[i]=max(dp[i],dp[i+1]);
             
         }
        
        for(int i=0;i<n;i++) cout<<dp[i]<<' ';
        cout<<endl;
        
        return dp[0];

    }
};
