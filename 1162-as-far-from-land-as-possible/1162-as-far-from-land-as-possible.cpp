class Solution {
public:
    bool issafe(int i,int j,int n,vector<vector<int>> &g,vector<vector<int>> &vis)
    {
        return i>=0 and j>=0 and i<n and j<n and g[i][j]==0 and vis[i][j]==0; 
    }
    
    int maxDistance(vector<vector<int>>& g) {
        
       int maxdist=0;
       int n=g.size();
       int dx[4]={1,-1,0,0};
       int dy[4]={0,0,1,-1};
       vector<vector<int>>vis(n,vector<int>(n,0));
       
       queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==1){
                    q.push(make_pair(i,j));
                    vis[i][j]=1;
                }
            }
        }
         
        
       while(!q.empty())
       {
           int siz=q.size(); 
           
           while(siz--)
           {
               auto top=q.front();
               q.pop();
               
               for(int i=0;i<4;i++)
               {
                   int nx=top.first + dx[i];
                   int ny=top.second + dy[i];
                   
                   if(issafe(nx,ny,n,g,vis)){
                       vis[nx][ny]=1;
                       q.push(make_pair(nx,ny));
                   }
                   
               }
           } 
            
           if(q.size())
              maxdist++;
       }
        
       if(maxdist==0) return -1;
        
       return  maxdist;
    }
};