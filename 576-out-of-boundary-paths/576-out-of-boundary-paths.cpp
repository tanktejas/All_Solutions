class Solution {
public:
    int dp[51][51][51];
    int vis[51][51];
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int mod=1000000007;
    int nn,mm;
    
    int find(int i,int j,int rm){
        
        if(rm<0) return 0;
   
        if(i>=mm or i<=-1 or j>=nn or j<=-1) return 1;
          
        if(dp[i][j][rm]!=-1) return dp[i][j][rm];
        
        int way=0;
        
        for(int k=0;k<4;k++){
            int nx=i + dx[k];
            int ny=j + dy[k];
            
             int prev=0;
            
              way=(way + find(nx,ny,rm-1))%mod; 
          
         
        }
          
        return dp[i][j][rm]=(way%mod);
        
    }
    
    int findPaths(int m, int n, int maxMove, int s, int e) {
         memset(dp,-1,sizeof(dp)); 
        
         mm=m;
         nn=n; 
    
        return find(s,e,maxMove); 
          
        
    }
};