class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& re, vector<int>& ti) {
         
        vector<int>ind(n+1,0);
        vector<vector<int>>adj(n+1);
        
        for(int i=0;i<re.size();i++){
            adj[re[i][0]].push_back(re[i][1]);
            ind[re[i][1]]++;
        }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>currco;
         
        for(int i=1;i<=n;i++){
            
            if(!ind[i]){
                currco.push({ti[i-1],i});
            }
        }
     
        while(true){
            auto ele=currco.top();
            currco.pop();
           
            for(auto child:adj[ele.second]){
                ind[child]--; 
                if(ind[child]==0){ 
                    currco.push({ti[child-1]+ele.first,child});
                }
            } 
            
            if(currco.size()==0){
                return ele.first;
            }
            
            if(currco.size()==1 and adj[currco.top().second].size()==0){
               break;
            }
            
        } 
        
        return currco.top().first;
    }
};