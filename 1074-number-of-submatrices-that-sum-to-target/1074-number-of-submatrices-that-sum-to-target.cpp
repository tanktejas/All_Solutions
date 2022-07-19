class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int tar) {
           int n=mat.size(),m=mat[0].size();
           vector<vector<int>>pre(n+1,vector<int>(m+1,0));
            pre[n-1][m-1]=mat[n-1][m-1];
            for(int i=n-2;i>=0;i--){
                pre[i][m-1]=mat[i][m-1]+pre[i+1][m-1];
            }
            
            for(int i=m-2;i>=0;i--){
                pre[n-1][i]=mat[n-1][i]+pre[n-1][i+1];
            }
        
            for(int i=n-2;i>=0;i--){
               for(int j=m-2;j>=0;j--){
                   
                   pre[i][j] = pre[i+1][j] + pre[i][j+1] - pre[i+1][j+1] + mat[i][j];
                   
               }
           }
         
        int ans=0;
         for(int i=0;i<n;i++){
             
             for(int j=i+1;j<=n;j++){
                 
                 unordered_map<int,int>mp;
                 mp[0]=1;  
                 for(int k=m-1;k>=0;k--){
                     
                     int totsum=pre[i][k] - pre[j][k];
                     ans+=mp[totsum - tar];
                     mp[totsum]++;  
                     
                 }
                 
             }
         }
          
         return ans;
    }
};