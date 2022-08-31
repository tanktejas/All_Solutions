class Solution {
public:
    vector<vector<int>>vis,dp;
    int nn,mm;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    bool issafe(int i,int j)
    {
        return i>=0 and j>=0 and i<nn and j<mm and dp[i][j]==0;
    }
     
    bool issafe1(int i,int j)
    {
        return i>=0 and j>=0 and i<nn and j<mm;      
    }       
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& he) {
        int n=he.size();
        int m=he[0].size();
        nn=n;
        mm=m;
      
        queue<pair<int,int>>q;
        
        dp.resize(n,vector<int>(m,0));
        vis.resize(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++)
        { 
            vis[0][i]=1;
            q.push({0,i});  
        }
        
        for(int i=1;i<n;i++)
        {
            vis[i][0]=1;
            q.push({i,0});  
        }
        
        while(q.size()) 
        {
            auto a=q.front();
            q.pop();
        
            int x=a.first;
            int y=a.second;
            
            dp[x][y]=1;
            
            for(int i=0;i<4;i++)
            {
                int nx=x + dx[i];
                int ny=y + dy[i];
                
                if(issafe(nx,ny)){   
                    if(he[x][y] <= he[nx][ny] and !vis[nx][ny]){
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }  
                } 
                   
            }
            
        }       
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 cout<<dp[i][j]<<' ';
//             }
//             cout<<endl;
//         }
        
        vis.clear();
        vis.resize(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        { 
            
               vis[i][m-1]++; 
                q.push({i,m-1}); 
             
        }
        
        for(int i=0;i<m-1;i++)
        {       
             vis[n-1][i]++;   
               q.push({n-1,i});  
        }
     
        while(q.size())
        {
            auto a=q.front();
            q.pop();
        
            int x=a.first;
            int y=a.second;
            
            dp[x][y]++;  
            
            for(int i=0;i<4;i++)
            {
                int nx=x + dx[i];
                int ny=y + dy[i];
                
                if(issafe1(nx,ny)){
                    if(he[x][y] <= he[nx][ny] and !vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                }   
                
            }
            
        }
        
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==2){
                    ans.push_back({i,j});
                }
            }
        }
        
        
        
        return ans;
        
    }
};