class Solution {
public:
    vector<vector<int>>dp;
    int dx[8]={1,-1,0,0,-1,1,-1,1};
    int dy[8]={0,0,-1,1,-1,1,1,-1};
    
    bool issafe(vector<vector<int>>& g,int r,int c,int n){
         return r<n and c<n and r>=0 and c>=0 and g[r][c]==0;
    }
    
     
    
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        if(g[0][0]==1) return -1;
        int n=g.size();
        if(n==1 and g[0][0]==0) return 1; 
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        vector<vector<int>>vis(n,vector<int>(n,0));
        int cnt=1;
        vis[0][0]=1; 
        
        while(!q.empty()){
            
            int qs=q.size();
            cnt++;
             
            while(qs--){
                auto aa=q.front();
                q.pop();
                
                for(int i=0;i<8;i++){
                    int nx=aa.first+dx[i],ny=aa.second+dy[i];
                    
                    if(nx==n-1 and ny==n-1 and g[nx][ny]==0) return cnt;
                    
                    if(issafe(g,nx,ny,n) and !vis[nx][ny]){
                        vis[nx][ny]=1;
                        q.push(make_pair(nx,ny)); 
                    }
                }
                
            }
             
        }
        return -1;
    }
};