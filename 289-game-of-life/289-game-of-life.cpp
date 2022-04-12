class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        int dx[8]={0,0,1,-1,-1,1,1,-1};
        int dy[8]={1,-1,0,0,1,1,-1,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cntone=0;
                for(int k=0;k<8;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx>=0 and ny>=0 and nx<m and ny<n){
                         if(abs(board[nx][ny])==1){
                             cntone++;  
                         }
                    }
                }
                if(board[i][j]==1){
                     if(cntone<2 or cntone>3) board[i][j]=-board[i][j]; 
                }else{
                      board[i][j]=2;    
                    
                      if(cntone!=3) board[i][j]=-board[i][j];
                }
            }
        }
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]>0){
                    board[i][j]=1;
                }else{
                    board[i][j]=0;  
                }
            }
        }
    } 
};