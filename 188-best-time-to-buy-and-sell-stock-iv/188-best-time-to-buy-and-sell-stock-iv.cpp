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
     
//         for(int i=1;i<n;i++)
//         {
//             if(pri[i]<pri[i-1]){
//                 tot.push_back(pri[i-1]-f);
//                 f=pri[i];
//             }
//         }
         
//           tot.push_back(pri[n-1]-f);
        
//           int no=tot.size();
      
//          for(int i=0;i<no;i++) cout<<tot[i]<<" ";
//          cout<<endl;
        
//         if(no<=k){      
//            return accumulate(tot.begin(),tot.end(),0);
//         }
        
         c=pri;
        
         memset(dp,-1,sizeof(dp));
        
          int maxpro=0;
           find(0,k,n);
          for(int i=0;i<n;i++)
          {
              maxpro=max(maxpro,dp[i][k]);
          } 
          
          return maxpro; 
    }
};