class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        int cnt=4;
        
        while(cnt--){
        
            int bo=1;
            
        vector<vector<int>>temp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            
            int j=0,k=n-1;
            
            while(j<n)
            {
                if(mat[k][i] != target[i][j]){
                    bo=0;
                }
                temp[k][i]=mat[i][j];
                j++;
                k--;
            }
            
        }
        
        mat= temp;
         
        if(bo) return 1;
            
        }
        
        return 0;
        
    }
};