class Solution {
public:
    int dp[302][11];
    
//     int find(int s,int d,int n,vector<int> &jd)
//     {
//         if(d==0 and s==n)
//         {
//             return 0;
//         }
        
//         if(d==0 or s==n)
//         {   
//             return -1;
//         } 
        
//         if(dp[s][d]!=-1) return dp[s][d];
        
//         int maxi=jd[s];
//         int ans=INT_MAX;
        
//         for(int i=s;i<n;i++)
//         {
//             maxi=max(maxi,jd[i]);
//             int pick=find(i+1,d-1,n,jd);
            
//             if(pick != -1 and pick != INT_MAX)
//             {
//                 ans=min(ans,maxi + pick);
//             }
//         }
        
//         return dp[s][d]=ans;
        
//     }
    
//      i -> job (1 base)
//      j -> day
     
//      dp[0][0] = 0;
//      dp[i][0] = INT_MAX;
     
         
//      i>=j then possible 
//           dp[i][j]= min(dp[i-k][j-1] for all  k)
//      else we will not explore that
         
    int minDifficulty(vector<int>& jd, int d) {
        // memset(dp,INT_MAX,sizeof(dp));
        int n=jd.size();
        
        for(int i=0;i<=301;i++)
        {
            for(int j=0;j<=10;j++)
            {
                dp[i][j]=INT_MAX;
            }
        }
        
        dp[0][0]=0;
        
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j<=d;j++)
            {  
                 
                if(i>=j){
                 int  maxi=jd[i-1];
                    
                for(int k=1;k<=i;k++)
                { 
                     maxi=max(maxi,jd[i-k]);
                     int ans=dp[i-k][j-1]; 
                     if(ans!=INT_MAX)
                     {
                         dp[i][j]=min(dp[i][j],ans + maxi);     
                     }
                    
                }  
                    
                }
            }
        }
        
      
        return dp[n][d]==INT_MAX ? -1 : dp[n][d];
          
        // int ans = find(0,d,n,jd);
        
        // if(ans==INT_MAX or ans==-1) return -1;
        // return ans;
        
    }
};