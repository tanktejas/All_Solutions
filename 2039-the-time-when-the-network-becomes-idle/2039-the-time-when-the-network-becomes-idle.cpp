class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& ed, vector<int>& p) {
        int n=p.size();
        vector<vector<int>>adj(n+1);
        vector<int>vis(n+1,0);

        for(int i=0;i<ed.size();i++){
            int u=ed[i][0],v=ed[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vis[0]=1;
        vector<int>dis(n+1,0);
        queue<int>q;
        int cnt=0;
        
        q.push(0);
        q.push(-1);
        while(!q.empty()){ 
            
            int ele=q.front();
            q.pop();
            
            for(auto ee:adj[ele]){
                 if(!vis[ee]){
                     vis[ee]=1;
                     dis[ee]=cnt+1;
                     q.push(ee);
                 } 
            }
            if(q.front()==-1){
                q.pop();
                
                if(!q.empty())
                   q.push(-1);
               cnt++;
            }
            // cout<<q.front()<<" ";  
            // cnt++;
        }
        
        for(int i=0;i<n;i++){
             // cout<<dis[i]<<" ";
        }
        cout<<endl;
        int maxi=0;
        for(int i=0;i<n;i++){ 
          
                if((2*dis[i]) <= p[i]){ 
                    maxi=max(maxi,2*dis[i]); 
                } 
                else{
                     int time=(2*dis[i])/p[i];
                      
                     if(((2*dis[i])%p[i])==0){
                         time--;
                     }
                     cout<<time<<" ";
                     int lastreq=time*p[i];
                    
                    maxi=max(maxi,((2*dis[i])+lastreq)); 
                } 
            
        }
        
        return maxi+1;
    }
};