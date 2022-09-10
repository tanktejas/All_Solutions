class Solution {
public:
     int dp[1001][101];
     vector<int>c;
    
    int find(int idx,int tr,int n){
        if(idx>=n) return 0;
        
        if(tr==0) return 0;
        
        if(dp[idx][tr]!=-1) return dp[idx][tr];
        
        int maxpro=0;
        
        int buyat=c[idx];
         
        for(int i=idx;i<n;i++)
        {
           
            maxpro=max(maxpro,(c[i]-c[idx])+find(i+1,tr-1,n));
           
        }
        
        maxpro=max(maxpro,find(idx+1,tr,n));
        
       return dp[idx][tr]=maxpro;
        
    }
    
    int maxProfit(int k, vector<int>& pri) {
              
        if(pri.size()==0) return 0;  
        int n=pri.size();
 
         c=pri;
        
         memset(dp,-1,sizeof(dp));
        
          int maxpro=0;
          maxpro=find(0,k,n);
 
          
          return maxpro; 
    }
};