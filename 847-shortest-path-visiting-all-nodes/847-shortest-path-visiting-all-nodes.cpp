class Solution{
public:
    
    int shortestPathLength(vector<vector<int>>& g) {
         int n=g.size(); 
        // return 1;
         int finals=(1<<n)-1;
            
         vector<vector<int>>vis(n,vector<int>(finals+1,0));
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){  
           q.push({i,(1<<(i))});
        }
        
        int sp=0;
        while(!q.empty()){
            int siz=q.size();
            sp++;
            while(siz--){
                auto curr=q.front();
                q.pop();
                
                int nodeid=curr.first;
                int currbit=curr.second;
                
                for(auto ele:g[nodeid]){
                    int cb=(currbit) | (1<<ele);
                    
                    if(cb==finals) return sp;
                    
                    if(!vis[ele][cb]){
                        vis[ele][cb]=1;
                        q.push({ ele,cb});
                    }
                    
                }  
                
            }
        } 
               return 0;
    }
 
    };