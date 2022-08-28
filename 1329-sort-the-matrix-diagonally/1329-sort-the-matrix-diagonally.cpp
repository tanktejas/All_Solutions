class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>v(n,vector<int>(m,0)),vis(n,vector<int>(m,0));
        
         vector<vector<int>>p(n+m);
         
         int i=n-1;
         int j=0;
         
         int io=0;
         
         while(i>0)
         {
             j=0;
             int o=i;
             while((o<n and j<m))
             {
                p[io].push_back(mat[o][j]);
                o++;
                j++;
             }
             sort(p[io].begin(),p[io].end());
             i--;
             io++;
         }
        
        
         i=0;
         j=0; 
        
         while(j<m)
         {
             i=0;
             int o=j;
             while((i<n and o<m))
             {
                p[io].push_back(mat[i][o]);
                i++;
                o++;
             }
             sort(p[io].begin(),p[io].end());
             io++;
             j++;
         }
          
        
           i=n-1;
           j=0;
         
          io=0;  
        
         while(i>0)
         {
             j=0;
             int o=i;
             while((o<n and j<m))
             { 
                mat[o][j]=p[io][j];
                o++;
                j++;
             }
             i--;
             io++;
         }
        
         i=0;
         j=0; 
        
         while(j<m)
         {
             i=0;
             int o=j;
             while((i<n and o<m))
             {
                mat[i][o]=p[io][i];
                i++;
                o++;
             }
             io++;
             j++;
         }
            

        return mat;
    }
};