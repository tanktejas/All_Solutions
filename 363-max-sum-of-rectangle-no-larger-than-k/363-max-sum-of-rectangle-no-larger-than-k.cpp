// class Solution {
// public:
//     vector<vector<int>>pre;
     
//     int maxSumSubmatrix(vector<vector<int>>& mat, int ko) {
          
//          int msum=INT_MIN; 
//          int n=mat.size();
//          int m=mat[0].size();
        
//          pre.resize(n+1,vector<int>(m+1,0));
         
//          pre[n-1][m-1]=mat[n-1][m-1];
        
//          for(int i=n-2;i>=0;i--)
//          {
//              pre[i][m-1]=pre[i+1][m-1]+mat[i][m-1];
//          }
        
//          for(int i=m-2;i>=0;i--)
//          {
//              pre[n-1][i]=pre[n-1][i+1]+mat[n-1][i];
//          }
         
//          for(int i=n-2;i>=0;i--)
//          {
//              for(int j=m-2;j>=0;j--)
//              {
//                  pre[i][j]=pre[i+1][j] + pre[i][j+1] - pre[i+1][j+1] + mat[i][j]; 
//              }
//          }
//          int cs;
//          for(int i=0;i<n;i++)
//          {   
//              for(int j=0;j<m;j++)
//              {
//                  for(int k=i+1;k<=n;k++)
//                  {  
//                      for(int l=j+1;l<=m;l++)
//                      { 
//                           cs=pre[i][j] + pre[k][l] - pre[i][l] - pre[k][j];   
//                          if(cs<=ko and msum<cs)
//                          {      
//                              msum=cs;
//                          }  
//                      }    
//                  }     
//              }
//          }
        
//         if(msum == INT_MIN) return -1; 
//         return msum;
//     }
// };

typedef int ll;
class Solution {
public:
    ll dp[105][105];
 
    ll get(ll x1,ll y1,ll x2,ll y2){
        return dp[x2+1][y2+1] - dp[x1][y2+1] - dp[x2+1][y1] + dp[x1][y1];
    }
    int maxSumSubmatrix(vector<vector<int>>& arr, int ch) {
        ll n = arr.size(),m = arr[0].size();
        for(ll i = 0;i <= n;i++){
            for(ll j = 0;j <= m;j++){
                dp[i][j] = 0;
            }
        }
        for(ll i = 1;i <= n;i++){
            for(ll j = 1;j <= m;j++){
                dp[i][j] = arr[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        ll ans = -INT_MAX;
        for(ll i = 0;i < n;i++){
            for(ll j = 0;j < m;j++){
                for(ll k = i;k < n;k++){
                    for(ll l = j;l < m;l++){
                        
                        ll temp = get(i, j, k, l);
                        if(temp > ans && temp <= ch)
                            ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};