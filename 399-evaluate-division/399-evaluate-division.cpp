class Solution {
public:

    unordered_map<string,vector<pair<string,double>>>adj;
    unordered_map<string,int>vis;
    
    bool dfs(string src,string dest,double currval,double &finalval){
        if(src==dest and adj.find(src)!=adj.end()){
            finalval=currval;
            return 1;
        }
        vis[src]=1;
        bool currans=0;
        for(auto ele:adj[src]){
            if(!vis[ele.first]){
                
                currans=dfs(ele.first,dest,currval*ele.second,finalval);
                if(currans){
                    break;
                }
                
            }
        } 
        
        vis[src]=0; 
        return currans;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
         int n=eq.size();
        for(int i=0;i<n;i++){
            adj[eq[i][0]].push_back(make_pair(eq[i][1],val[i]));
            adj[eq[i][1]].push_back(make_pair(eq[i][0],1/val[i]));
            
            vis[eq[i][0]]=0;
            vis[eq[i][1]]=0;
        }
        int m=q.size();
        vector<double>ans(m);
        for(int i=0;i<m;i++){
            double qans=1;
            bool is=dfs(q[i][0],q[i][1],1.0,qans);
            if(is){ 
                ans[i]=qans;
            }else{
                ans[i]=-1.0;
            }
        }
        return ans;
    }
};