class Solution {
public: 
    double pp;
    bool find(vector<vector<int>> &v,vector<int> &vis,int s,int time,int tar,double prob){
        
         if(time<0){
             return 0;
         }
        
        if(s==tar and (time==0 or v[s].size()==1)){
            pp=prob;
            return 1;
        }
        
        vis[s]=1;
        int ans=0; 
        
        for(auto ele:v[s]){
          if(!vis[ele]){ 
              if(find(v,vis,ele,time-1,tar,prob/(v[s].size()-1))) return 1;
          }
        }
         
         return 0;
    }
    
    double frogPosition(int n, vector<vector<int>>& ed, int t, int target) {
        double ans=1.000;
        vector<vector<int>>adj(n+1);
        
        for(int i=0;i<ed.size();i++){
            int u=ed[i][0];
            int v=ed[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        adj[1].push_back(0);
        vector<int>vis(n+1,0);
    
        // return 1.00;
        
        if(find(adj,vis,1,t,target,ans))
            return pp;
        else 
            return 0.00000;
    }
};