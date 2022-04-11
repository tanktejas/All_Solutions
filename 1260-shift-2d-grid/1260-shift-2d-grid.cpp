class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>v;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }     
        k=k%(v.size());
        int rotatestart=v.size()-k; 
        vector<vector<int>>ans(m,vector<int>(n)); 
        if(rotatestart>=v.size()) rotatestart=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=v[rotatestart];
                  rotatestart++;
                if(rotatestart>=v.size()){
                    rotatestart=0;
                } 
            }
        }
        return ans;
    }
};