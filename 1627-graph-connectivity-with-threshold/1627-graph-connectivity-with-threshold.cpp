
  
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
     
    vector<bool> areConnected(int n, int th, vector<vector<int>>& q) {
        DSU d; 
               
        vector<bool>ans;
        
        for(int i=1;i<=n;i++){
            d.par[i]=i;   
            d.siz[i]=1;
        }
         
        
        for(int i=th+1;i<=n;i++){   
            
            for(int j=i;j<=n;j+=i)
            {    
                d.makeuni(i-1,j-1);
            }
        }
         
        for(int i=0;i<q.size();i++)
        {  
             // cout<<d.findpar(q[i][0])<<' '<<d.findpar(q[i][1])<<endl; 
             ans.push_back(d.findpar(q[i][0]-1)==d.findpar(q[i][1]-1));
        }
        
        return ans;
        
    }
};