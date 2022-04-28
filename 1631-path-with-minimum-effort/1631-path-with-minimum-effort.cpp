class Solution {
public:
    bool issafe(int nx,int ny,int n,int m,vector<vector<int>> &vis){
        return nx>= 0 and ny>=0 and nx<n and ny<m and !vis[nx][ny];
    }
     bool will(vector<vector<int>>& h,int mid){
         queue<vector<int>>q;
         q.push({0,0});
         int n=h.size();
         int m=h[0].size();
         
         vector<vector<int>>vis(n,vector<int>(m,0));
         vis[0][0]=1;
         
         while(!q.empty()){
             
             auto vec=q.front();
             q.pop();
             
             int dx[4]={0,0,1,-1};
             int dy[4]={1,-1,0,0};
             
             if(vec[0]==n-1 and vec[1]==m-1) return 1;
             
             for(int i=0;i<4;i++){
                 int nx=vec[0]+dx[i];
                 int ny=vec[1]+dy[i];
                 
                 if(issafe(nx,ny,n,m,vis)){
                     if(abs(h[nx][ny]-h[vec[0]][vec[1]])<=mid){
                         vis[nx][ny]=1;
                         q.push({nx,ny});
                     }
                 }
                 
             }
             
         }
         
         return 0;
         
     }
    int minimumEffortPath(vector<vector<int>>& h) {
        int mindiff=INT_MAX;
        int s=0,e=INT_MAX;
        while(s<=e){    
            int mid=(s+e)/2;
            if(will(h,mid)){
                e=mid-1;
                mindiff=mid;
            }else{
                s=mid+1;
            }
        }
        return mindiff;
    }
};