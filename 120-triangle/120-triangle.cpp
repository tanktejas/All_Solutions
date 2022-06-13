class Solution {
public:
    vector<vector<int>>dp;
    
    int find(vector<vector<int>> &tri,int row,int col,int n){
        if(row==n){
            return 0;
        }
        if(col==(int)(tri[row].size())) return 0;
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int maxi=INT_MAX;
        
        maxi=min(maxi,tri[row][col] + find(tri,row+1,col,n));
        
        maxi=min(maxi,tri[row][col] +find(tri,row+1,col+1,n));
        
        return dp[row][col] = maxi;
    }
    
    int minimumTotal(vector<vector<int>>& tri) {
         int n=tri[tri.size()-1].size();
        
         dp.resize(n,vector<int>(n,-1));

       return find(tri,0,0,n);
    }
};