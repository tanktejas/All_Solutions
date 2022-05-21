class Solution {
public:
    vector<vector<int>>dp;
    
    int find(int s,int n,vector<int> &c,int am){
        if(am==0)
              return 0;
        if(s==n){ 
              return INT_MAX-1;  
        }
         
        if(am<0){
            return INT_MAX-1;
        }
        
        if(dp[s][am]!=INT_MAX) return dp[s][am];
         
        
        dp[s][am]=min(1 + find(s,n,c,am-c[s]),find(s+1,n,c,am)); 
        
        return dp[s][am];
        
    }
    
    int coinChange(vector<int>& c, int am) {
        sort(c.begin(),c.end(),greater<int>());
        int n=c.size();
        dp=vector<vector<int>>(n,vector<int>(am+1,INT_MAX));
        int ans=find(0,n,c,am); 
        if(ans>=INT_MAX-1) return -1;
        return ans;
    } 
};