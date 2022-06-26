class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int color) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int m=im.size(),n=im[0].size();
        
        queue<pair<int,int>>q;
        
        q.push({sr,sc});
        int pc=im[sr][sc];
        
        if(pc==color) return im;
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            im[ele.first][ele.second]=color;
            
            for(int i=0;i<4;i++){
                int nx=dx[i]+ele.first;
                int ny=dy[i]+ele.second;
                
                if(nx>=0 and ny>=0 and nx<m and ny<n and im[nx][ny]==pc){   
                    q.push({nx,ny}); 
                }  
            } 
        
        }
        
        return im;
    }
};