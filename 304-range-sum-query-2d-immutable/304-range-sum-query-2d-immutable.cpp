class NumMatrix {
public:
    vector<vector<int>>pre;
    int n,m;
    NumMatrix(vector<vector<int>>& mat) {
       n=mat.size(),m=mat[0].size();
        pre=vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            
            pre[i][1]=mat[i-1][0];
            
            for(int j=2;j<=m;j++){
               pre[i][j]=mat[i-1][j-1]+pre[i][j-1];     
            }
            
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
         row1++,col1++,row2++,col2++;
        for(int i=row1;i<=row2;i++){
            ans+=(pre[i][col2]-pre[i][col1-1]);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */