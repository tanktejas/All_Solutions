class Solution {
public:
    
    vector<vector<int>>dp;
    int mm;
    int nn;
    
    int find(int i,int j)
    {

        if(i==mm-1 and j==nn-1) return 1;
        
        if(i<0 or j<0 or i>=mm or j>=nn)
        {
            return INT_MAX;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right=find(i,j+1);
        int bott=find(i+1,j);
        int tot=0;
        
        if(right != INT_MAX) tot+=right;
        if(bott != INT_MAX) tot+=bott;
        
        return dp[i][j]=tot;
        
    }
    
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        mm=m;
        nn=n;
        return find(0,0);
         
    }
};