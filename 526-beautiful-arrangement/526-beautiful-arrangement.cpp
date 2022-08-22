class Solution {
public:
      int ans=0;
      int nn;
      vector<int>v;
     
     void tryall(int idx)
     {
         if(idx==nn)
         {   
             ans+=1; 
             return ;  
         }
         
         for(int i=idx;i<nn;i++)
         { 
            if((v[i]%(idx+1) == 0 or (idx+1)%v[i]==0)){
                
             swap(v[i],v[idx]);     
             tryall(idx+1);      
             swap(v[i],v[idx]);
                
            }     
         }  
         
     }   
     
    int countArrangement(int n) {
        nn=n;
        
        for(int i=1;i<=n;i++) v.push_back(i);
        
        tryall(0);
        
        return ans;
    }
};  



