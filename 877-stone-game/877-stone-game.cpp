class Solution {
public:
     vector<vector<int>>dp;
    vector<int>st; 
    
    int find(int i,int j,int turn){
    
     if(i>=j) return 0;  
        // if(j==i+1) return max(st[i],st[j]);
        
     if(dp[i][j]!=-1) return dp[i][j];
    
     int curr=0;
    
     if(turn == 0)
     {
         
        int pick0=(st[j] + find(i,j-1,1));
        int pick1=(st[i] + find(i+1,j,1));
        
        dp[i][j]=max(pick0 , pick1);
         
     }else{
         
        int pick0=(find(i,j-1,0) - (st[j]));
        int pick1=(find(i+1,j,0) - (st[i]));  
        
        dp[i][j]=min(pick0 , pick1);
         
     }
         
    return dp[i][j];
  }
    
    bool stoneGame(vector<int>& piles) {
        st.resize(piles.size()+1,0);
        int n=piles.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<piles.size();i++){
            st[i+1]=piles[i];
        }
        
        int yy=find(1,piles.size(),0);
        
        return yy>0;
    }
};