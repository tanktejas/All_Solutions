class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        
        int cnt=n-1;
        int rs=0,cs=0,re=n-1,ce=n-1;
        int io=0,j=0;
        
        while(rs<re)
        {  
            int rota=cnt; 
            
            while(rota--)
            {
                int reser=mat[io][j];  
                for(int i=cs+1;i<=ce;i++)
                {   
                    swap(reser,mat[rs][i]);
                }
                
                for(int i=rs+1;i<=re;i++)
                {
                    swap(reser,mat[i][ce]);
                }
                 
                for(int i=ce-1;i>=cs;i--)
                {
                    swap(reser,mat[re][i]);
                }
                
                for(int i=re-1;i>rs;i--)
                {
                    swap(reser,mat[i][cs]);
                }
                
                swap(reser,mat[io][j]);  
                
            }
            
            
            io++;
            j++;
            
            cnt-=2;
             rs++;
             ce--;
             re--; 
             cs++;
        }
        
    }
};