class Solution {
public:
    vector<vector<int>>dp;
    vector<int>st;
    vector<int>pre;
    
    int find(int i,int j,int turn){
    
     if(i>=j) return 0;   
        
     if(dp[i][j]!=-1) return dp[i][j];
    
     int curr=0;
 
         
        int pick0=(pre[j-1]-pre[i-1] - find(i,j-1,1));  // opponent will try to minimize diffrence by taking his diffrence maximum.  
        int pick1=(pre[j]-pre[i] - find(i+1,j,1));
        
        dp[i][j]=max(pick0 , pick1);
          
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