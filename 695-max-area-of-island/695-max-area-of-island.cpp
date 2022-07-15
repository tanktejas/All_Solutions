class Solution {
public:
    bool issafe(int i,int j,int m,int n,vector<vector<int>>& g){
        return i>=0 and j>=0 and i<m and j<n and g[i][j]==1;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int m=g.size(),n=g[0].size();
        queue<pair<int,int>>q;
        
        int ml=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cl=0;
                
                if(g[i][j]==1){
                  q.push({i,j});
                  g[i][j]=0;
                  while(!q.empty()){
                      auto ele=q.front(); 
                      q.pop();
                      cl++;
                      for(int k=0;k<4;k++){
                         int nx=ele.first + dx[k];
                         int ny=ele.second + dy[k];
                          
                         if(issafe(nx,ny,m,n,g)){
                             q.push({nx,ny});
                              g[nx][ny]=0;
                         }
                          
                      }
                       
                  }
                
                }
                ml=max(ml,cl);
                
            }
        }
        return ml;
    }
};