class Solution {
public:
    
    // we don't need to take visited array because our dp state is j,j,k so if we reach ith row and jth olumn then it doen't mean that we don't need to go there in fact we nned to go there because our k is affacted which is number of moves right so our state is i...j...k.
    
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