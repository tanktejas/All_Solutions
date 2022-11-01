class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
        
        int n=g.size();
        int m=g[0].size();
        
        vector<int>ans;
        
        for(int i=0;i<m;i++)
        {
            int row=0,col=i;
            
            bool bo=1; 
            while(bo and row!=n)
            {
                int cr=row,cc=col;
               
                if((g[row][col]==1 and (col==m-1 or g[row][col+1]==-1)) or (g[row][col]==-1 and (col == 0 or g[row][col-1]==1)))
                {
                    bo=0;
                    break;
                }else if(g[row][col]==1){
                    row+=1;
                    col+=1;
                }else{
                    row+=1;
                    col-=1;
                }
            }
            
            if(bo and row==n)
            {
                ans.push_back(col);
            }else{
                ans.push_back(-1);
            }
            
        }
        return ans;
    }
};   