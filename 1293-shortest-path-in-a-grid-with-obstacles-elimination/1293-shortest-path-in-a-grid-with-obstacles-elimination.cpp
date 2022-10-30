class Solution {
public:
    
    vector<vector<int>>vis;
    vector<vector<vector<long long>>>dp;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int nn,mm;
    
    
    int find(vector<vector<int>>& g,int x,int y,int k)
    {
        if(k<0) return INT_MAX;
         
         
        if(dp[x][y][k] != INT_MAX)
        {
            // cout<<dp[x][y][k]<<" ";
            return dp[x][y][k];
        }  
          
        
        vis[x][y]=1;
         
        
        int cmin=INT_MAX;
        
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
             
            
            if(nx>=0 and nx<nn and ny>=0 and ny<mm and vis[nx][ny]==0)
            {
               if(g[nx][ny]==1)
               {
                   k--;
               }
                
               int yy=find(g,nx,ny,k--);
               
               if(yy<cmin)
               {
                   cmin=yy;
               }
                
            }
             
        }
         
        
        vis[x][y]=0;
         
        if(cmin!=INT_MAX)
        {
            dp[x][y][k]=1+cmin;
        }
         
        
        return dp[x][y][k];
        
    }
    
    int shortestPath(vector<vector<int>>& g, int k) {
        
        int n=g.size();
        int m=g[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        int ans=0;
        
        queue<vector<int>>q;
        
        q.push({0,0,k});
        
        while(!q.empty())
        {
            int siz=q.size(); 
             
            while(siz--)
            {
                
            auto ele=q.front();
            q.pop();
                
            // cout<<ele[0];
            
            if(ele[0]==n-1 and ele[1]==m-1) return ans;
            
             
            for(int i=0;i<4;i++)
            {
                int nx=ele[0]+dx[i];
                int ny=ele[1]+dy[i];
                 
                
                if(nx>=0 and nx<n and ny>=0 and ny<m and (ele[2]-g[nx][ny])>=0 and vis[nx][ny] < (ele[2]-g[nx][ny]))
                {   
                     vis[nx][ny] = ele[2]-g[nx][ny];
                     q.push({nx,ny,ele[2]-g[nx][ny]});
                }
                
             }
                
            }
            
            ans++;
            
        }
        
        return -1;
        
        
    }
};