class Solution {
public:
    vector<vector<int>>ans;
    vector<int>dis,low;
    vector<int>vis,par;
    int time;
    void find(vector<vector<int>> &v,int node){
        
         static int time=0;
             vis[node]=1; 
             dis[node]=time;
             low[node]=time;
             time++; 
            for(auto ele:v[node]){
                 
             if(!vis[ele]){
                par[ele]=node;
                find(v,ele);
                   
                 
                low[node]=min(low[ele],low[node]);
                     
                if(low[ele] > dis[node]){
                   ans.push_back({node,ele});    
                }
                 
            }else if(par[node]!=ele){
                 low[node]=min(dis[ele],low[node]);
             } 
            
        }
        
    }  
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& co) {
         vector<vector<int>>v(n);
         for(int i=0;i<co.size();i++){
             v[co[i][0]].push_back(co[i][1]);
             v[co[i][1]].push_back(co[i][0]);
         }
       dis=vector<int>(n,INT_MAX);
       low=vector<int>(n,INT_MAX);
       vis=vector<int>(n,0); 
       par=vector<int>(n,-1);
        
       find(v,0);
        
      return ans;
    }
};