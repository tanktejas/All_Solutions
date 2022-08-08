class Solution {
public:
    int mod=1e9+7;
    vector<vector<unsigned long long>>dp;
    int tot;
    int kk;
    
    int find(int in,int tar){
        if(tar==0 and in==(tot+1)) return 1;
        
        if(tar<0) return 0; 
        
        if(in>tot) return 0;
        
        if(dp[in][tar]!=-1) return dp[in][tar];
        
        unsigned long long ways=0;
        
        for(int i=1;i<=kk;i++)
        {
            
            unsigned long long gg= (ways);
            unsigned long long hh= (find(in+1,tar-i));  
            ways=(gg + hh)%mod;   
        }
         
        return dp[in][tar]=ways;
    }
    
    int numRollsToTarget(int n, int k, int tar) {  
      dp.resize(n+3,vector<unsigned long long>(tar+3,-1));
      tot=n;
      kk=k;
         
      return find(1,tar);
        
    }
};