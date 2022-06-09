class Solution {
public:
     
    void setZeroes(vector<vector<int>>& mat) {
         long long ele=pow(2,31);
         int flag=mat[0][0];
        int m=mat.size();
        int n=mat[0].size();
        
        int col0=1,row0=1;
        
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    if(i==0) row0=0;
                    if(j==0) col0=0;
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
             }
         }
        
          
        for(int i=1;i<m;i++){
            if(mat[i][0]==0){
                for(int j=1;j<n;j++){
                    mat[i][j]=0;
                }
            }
        }
           for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 cout<<mat[i][j]<<" ";
             }
             cout<<endl;
         } 
        
         for(int i=1;i<n;i++){
            if(mat[0][i]==0){
                for(int j=1;j<m;j++){
                    mat[j][i]=0;
                }
            }
        }
        
        if(flag==0){
            for(int i=1;i<n;i++){
                mat[0][i]=0;
            }
             for(int i=1;i<m;i++){
                mat[i][0]=0;
            }
        }else{
            if(col0==0){
                for(int i=0;i<m;i++) mat[i][0]=0;
            }
            if(row0==0){
                for(int i=0;i<n;i++) mat[0][i]=0;
            }
        }
        
        
    }
};