
  
 class DSU{
    
   public: 
     
    unordered_map<int,int>par;    
    unordered_map<int,int>siz;
    
    int findpar(int ele){ 
        if(ele==par[ele]){
            return ele;
        }
        return par[ele]=findpar(par[ele]);   
    }
    
    void makeuni(int e1,int e2){
        int p1=findpar(e1);
        int p2=findpar(e2);
        
        if(siz[p1] <= siz[p2]){
            par[p1]=par[p2]; 
            siz[p2]+=siz[p1];
            siz[p1]=0;
        }else if(siz[p2] < siz[p1]){
            par[p2]=par[p1];
            siz[p1]+=siz[p2];
            siz[p2]=0;
        } 
    }
 };



class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
          DSU dsu;
         vector<int>ans(2,-1);
         int n=edges.size();
         int du=0,tnode=0;
         
        vector<int>ind(n+1,-1); 
        int prev=-1,next=-1;
        for(int i=0;i<n;i++){
            
              int f=edges[i][0];
              int s=edges[i][1];
              if(dsu.par[f]==0) dsu.par[f]=f;
              if(dsu.par[s]==0) dsu.par[s]=s;
              
               if(dsu.siz[f]==0) dsu.siz[f]=1;
               if(dsu.siz[s]==0) dsu.siz[s]=1;
             
            if(ind[edges[i][1]]>=0){
                prev=ind[edges[i][1]];
                next=i;
            }else{
                ind[edges[i][1]]=i;
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==next) continue;
            
            int p1=dsu.findpar(edges[i][0]);
            int p2=dsu.findpar(edges[i][1]);
            
            if(p1==p2){
                cout<<prev;
                if(prev!=-1){
                    return {edges[prev][0],edges[prev][1]};
                }else{
                    return {edges[i][0],edges[i][1]};
                }
            }else{
                 dsu.makeuni(edges[i][0],edges[i][1]);
            }
        }
        
        return {edges[next][0],edges[next][1]};    
    }
};