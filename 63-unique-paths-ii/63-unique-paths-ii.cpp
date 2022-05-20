class Solution {
public:
    vector<vector<int>>dp;
    bool issafe(int i,int j,int n,int m,vector<vector<int>> &og){
        return i>=0 and j>=0 and i<n and j<m and og[i][j]==0;
    }
    int find(int r,int c,vector<vector<int>> &og,int n,int m){
        if(!issafe(r,c,n,m,og)){
            return 0;
        }
        if(r==n-1 and c==m-1){
            dp[r][c]=1;
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        
       int left= find(r+1,c,og,n,m);
       int right= find(r,c+1,og,n,m);
        
    return dp[r][c]=left+right;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n=og.size(),m=og[0].size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
       return find(0,0,og,n,m);
    }
};