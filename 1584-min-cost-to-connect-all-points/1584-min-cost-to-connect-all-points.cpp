class Solution {
public:

    vector<int>par;
    vector<int>size; 
    
    int findpar(int child){
        if(par[child]==child){
            return child;
        }
        return par[child]=findpar(par[child]);
    }
    
    void makeunion(int ele1,int ele2){
        
        int par1=findpar(ele1);
        int par2=findpar(ele2);
        
        if(size[par1]<size[par2]){
            par[par1]=par2;
            size[par2]+=size[par1]; 
            size[par1]=0;
        }else if(size[par1]>=size[par2]){
            par[par2]=par1;
            size[par1]+=size[par2]; 
            size[par2]=0;
        } 
        
        return ;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        par.resize(1000002);
        size.resize(1000002,1);
        
        int n=points.size();
        vector<pair<int,pair<int,int>>>edges;
         for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                 if(i!=j){
                     edges.push_back(make_pair(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),make_pair(i,j)));
                 }
             }
         }      
        sort(edges.begin(),edges.end());
        for(int i=0;i<1000002;i++){
            par[i]=i;
        }
        
        int ans=0;
        for(int i=0;i<edges.size();i++)
        { 
            int par1=findpar(edges[i].second.first);
            int par2=findpar(edges[i].second.second);
            
            if(par1!=par2){
                makeunion(edges[i].second.first,edges[i].second.second);
                ans+=edges[i].first; 
            }
        }
        return ans;
    }
};