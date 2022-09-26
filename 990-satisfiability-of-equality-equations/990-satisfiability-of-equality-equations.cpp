class Solution {
public:
    
  
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

    
    bool equationsPossible(vector<string>& eq) {
         DSU d;
        
         for(int i=0;i<=26;i++)
         {
           d.par[i]=i;
           d.siz[i]=1;
         }
         
         int n=eq.size();
        
         for(int i=0;i<n;i++)
         {
             int f=(eq[i][0] - 'a');
             int s=(eq[i][3] - 'a');
             
             if(eq[i][1]=='!')
             {  
                 int p1=d.findpar(f);
                 int p2=d.findpar(s); 
             }else{
                 d.makeuni(f,s);
             }
         }
        
        
         for(int i=0;i<n;i++)
         {
             int f=(eq[i][0] - 'a');
             int s=(eq[i][3] - 'a');
             
             if(eq[i][1]=='!')
             {  
                 int p1=d.findpar(f);
                 int p2=d.findpar(s); 
                 
                 if(p1==p2) return 0;
             }else{
                 int p1=d.findpar(f);
                 int p2=d.findpar(s); 
                 
                 if(p1!=p2) return 0;
             }
         }
         
        return 1; 
    }
};