
  
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         DSU dsu;
         vector<int>ans(2,-1);
         for(int i=0;i<edges.size();i++)
         {
             int f=edges[i][0];
             int s=edges[i][1];
              if(dsu.par[f]==0) dsu.par[f]=f;
              if(dsu.par[s]==0) dsu.par[s]=s;
              
               if(dsu.siz[f]==0) dsu.siz[f]=1;
               if(dsu.siz[s]==0) dsu.siz[s]=1;
             
             int pf=dsu.findpar(f);
             int ps=dsu.findpar(s);
             
             if(pf==ps){
                 ans[0]=f;
                 ans[1]=s;
             }else{
                 dsu.makeuni(f,s);
             }
             
         }
        
        return ans;
    }
};