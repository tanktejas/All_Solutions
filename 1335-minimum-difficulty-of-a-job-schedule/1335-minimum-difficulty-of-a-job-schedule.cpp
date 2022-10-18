class Solution {
public:
    int dp[301][11];
    
    int find(int s,int d,int n,vector<int> &jd)
    {
        if(d==0 and s==n)
        {
            return 0;
        }
        
        if(d==0 or s==n)
        {   
            return -1;
        } 
        
        if(dp[s][d]!=-1) return dp[s][d];
        
        int maxi=jd[s];
        int ans=INT_MAX;
        
        for(int i=s;i<n;i++)
        {
            maxi=max(maxi,jd[i]);
            int pick=find(i+1,d-1,n,jd);
            
            if(pick != -1 and pick != INT_MAX)
            {
                ans=min(ans,maxi + pick);
            }
        }
        
        return dp[s][d]=ans;
        
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        memset(dp,-1,sizeof(dp));
        int n=jd.size();
        
        int ans = find(0,d,n,jd);
        
        if(ans==INT_MAX or ans==-1) return -1;
        return ans;
        
    }
};