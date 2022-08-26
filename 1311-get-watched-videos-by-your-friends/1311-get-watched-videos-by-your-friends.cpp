bool cmp(pair<int,string> p1,pair<int,string> p2)
{
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    
    return p1.first < p2.first; 
}
 
class Solution {
public:
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& fr, int id, int lv) {
       
        int totfri=fr.size();
        
        vector<vector<int>>adj(totfri);
        
        for(int i=0;i<fr.size();i++)
        {
            int yy=fr[i].size();
            for(int j=0;j<yy;j++)
            {
                adj[i].push_back(fr[i][j]);
            }
        }
        
        int level=0;
        
        queue<int>q;
        q.push(id);
        vector<string>ans;
        vector<int>vis(totfri,0);
        vis[id]=1;
        
        while(!q.empty())
        {   
            if(level==lv) 
            { 
                map<string,int>m; 
                 
                while(!q.empty())
                {
                    int ele=q.front();   
                    q.pop();
                    for(int i=0;i<wv[ele].size();i++) 
                    { 
                        m[wv[ele][i]]++;    
                    } 
                     
                }
                
                   vector<pair<int,string>>as; 
                 
                    for(auto t:m)
                    {   
                       as.push_back(make_pair(t.second,t.first));
                    }  
                    
                    sort(as.begin(),as.end(),cmp);
                    
                    for(int i=0;i<as.size();i++)
                    {
                       ans.push_back(as[i].second);
                    }
                 
                  return ans;
            }
            
            int siz=q.size();
            
            while(siz--)
            {
                int top=q.front();
                q.pop(); 
                for(int i=0;i<adj[top].size();i++)
                {
                    if(!vis[adj[top][i]]){
                        vis[adj[top][i]]=1;
                        q.push(adj[top][i]);
                    }
                }
                
            } 
            
            level++;
            
        }
        
         return {};
        }
};