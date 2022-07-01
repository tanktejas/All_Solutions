class Solution {
public:
    vector<long long>sq,dp;
    
    int find(int idx,int n){
        
        if(n==0) return 0;
        
        if(idx>=sq.size() or n<0){
           return INT_MAX-1; 
        }
         
        if(dp[n]!=INT_MAX) return dp[n];
        
         long long p=1 + find(idx,n-sq[idx]);
         long long np=find(idx+1,n);
        
         return dp[n]=min(p,np);
        
    }
      
    int numSquares(int n) {
        for(int i=1;i*i<=n;i++){
            sq.push_back(i*i);  
        } 
        
        dp=vector<long long>(n+1,INT_MAX);
        find(0,n);
        
        for(int i=0;i<=n;i++) cout<<dp[i]<<' ';
        
        return dp[n];
    } 
};