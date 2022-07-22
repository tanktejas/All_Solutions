class Solution {
public:
    map<string,vector<string>>adj;
    map<pair<string,string>,int>vis;
    vector<string>ans,ans1;
    
    bool dfs(string so,int &n)
    {  
        
        if(ans.size()==n+1) 
        {   
            if(ans1.size()==0){
                ans1=ans;      
            } 
            return 1;
        }
        
        for(auto ele:adj[so])
        {
            if(vis[{so,ele}]!=0)
            {
                     vis[{so,ele}]--;
                     // if(vis[{so,ele}]==0) vis.erase({so,ele});
                     ans.push_back(ele);
                     if(dfs(ele,n)) return 1;  
                     ans.pop_back(); 
                     vis[{so,ele}]++; 
            }
        }
        return 0;
    }
    
    vector<string> findItinerary(vector<vector<string>>& ti) {
        int n=ti.size();
        for(int i=0;i<n;i++)
        {
            string s=ti[i][0];
            string d=ti[i][1];
            
            vis[{s,d}]++;
            
            adj[s].push_back(d);     
        }
        
       for(auto &vele:adj)
       {
           sort(vele.second.begin(),vele.second.end());
       }
       
        ans.push_back("JFK");
        
        dfs("JFK",n);
        
        return ans1;
        
    }
};