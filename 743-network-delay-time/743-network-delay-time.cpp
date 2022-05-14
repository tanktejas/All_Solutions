class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>adj(n+1);
       for(int i=0;i<times.size();i++)
       {
           int u=times[i][0],v=times[i][1],w=times[i][2];
           adj[u].push_back(make_pair(v,w));
       }
       vector<long long>dis(n+1,INT_MAX);
        dis[k]=0;  
        set<pair<int,int>>s;      //{wait,vertex}
        s.insert(make_pair(0,k));
        
        while(!s.empty()){
            auto pp=*s.begin();
            s.erase(s.begin());
            
            for(auto ele:adj[pp.second]){ 
                   // cout<<ele.first<<" "<<dis[pp.second] <<endl;  
                if(dis[ele.first] > (dis[pp.second]+ele.second)){  
                      s.erase(make_pair(dis[ele.first],ele.first));
                      dis[ele.first]=(dis[pp.second]+ele.second);
                      cout<<ele.first<<" "<<dis[pp.second]+ele.second<<endl;
                      s.insert(make_pair(dis[pp.second]+ele.second,ele.first));
                     
                }    
                // return 1;
                
            }
            // cout<<s.size()<<" "; 
        }
        
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
              if(ans<dis[i]) ans=dis[i];
        }
        
        return ans;
    }
};