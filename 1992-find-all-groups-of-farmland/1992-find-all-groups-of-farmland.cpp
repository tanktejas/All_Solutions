class Solution {
public:
    bool issafe(int i,int j,int m,int n,vector<vector<int>>& g){
        return i>=0 and j>=0 and i<m and j<n and g[i][j]==1;
    }
     
    vector<vector<int>> findFarmland(vector<vector<int>>& g) {
         int m=g.size(),n=g[0].size();
         
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1}; 
        queue<pair<int,int>>q;
         
        vector<vector<int>>ans;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cl=0;
                
                if(g[i][j]==1){ 
                  q.push({i,j});
                  g[i][j]=0;
                  bool bo=1;
        
                    cout<<1;
                    int tx,tr,bx,by;
                    tx=i;
                    tr=j;
                    bx=i;
                    by=j;
                  while(!q.empty()){
                      auto ele=q.front(); 
                      q.pop();
                      
                      bx=max(bx,ele.first);
                      by=max(by,ele.second);
                      
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
                  
                  ans.push_back({tx,tr,bx,by});
                  
                }
            }
        }   
        return ans;
        
    }
};