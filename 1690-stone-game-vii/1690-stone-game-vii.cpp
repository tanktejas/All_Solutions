class Solution {
public:
    vector<vector<int>>dp;
    vector<int>st;
    vector<int>pre;
    
    int find(int i,int j,int turn){
    
     if(i>=j) return 0;  
        // if(j==i+1) return max(st[i],st[j]);
        
     if(dp[i][j]!=-1) return dp[i][j];
    
     int curr=0;
    
     if(turn == 0)
     {
         
        int pick0=(pre[j-1]-pre[i-1] + find(i,j-1,1));
        int pick1=(pre[j]-pre[i] + find(i+1,j,1));
        
        dp[i][j]=max(pick0 , pick1);
         
     }else{
         
        int pick0=(find(i,j-1,0) - (pre[j-1]-pre[i-1]));
        int pick1=(find(i+1,j,0) - (pre[j]-pre[i]));  
        
        dp[i][j]=min(pick0 , pick1);
         
     }
         
    return dp[i][j];
  }
    
    
    int stoneGameVII(vector<int>& s) {
        int n=s.size();
        dp.resize(n+1, vector<int>(n+1,-1));
        st=s;
        pre.resize(n+1,0);
        pre[1]=s[0];
        
        for(int i=1;i<n;i++)
        {
          pre[i+1]=pre[i] + s[i];
        }
        
       return find(1,n,0);
        
    }
};