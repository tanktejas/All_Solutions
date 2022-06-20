class Solution {
public:
    int minOperationsMaxProfit(vector<int>& cu, int bc, int rc) {
       int cs=0;
       int maxi=-1;
       int n=cu.size();
        int rot=-1;
        int gg=0;
        int i=0;
       for(i=0;i<n;i++)
       {
          
           cs+=cu[i];
           if(cs>=4){
              gg+=4;
              cs-=4;
              int pro=(gg * bc) - (rc * (i+1)); 
              if(pro > maxi){
                   rot=i+1;  
              }
              maxi=max(maxi,pro);
           }else
           {
              gg+=cs;
              cs=0;
              int pro=gg * bc - (rc * (i+1));
              if(pro > maxi){
                   rot=i+1;
              }
              maxi=max(maxi,pro);   
           }
       } 
        
        while(cs>0){
           if(cs>=4){
              gg+=4;
              cs-=4;
              int pro=(gg * bc) - (rc * (i+1)); 
              if(pro > maxi){
                   rot=i+1;  
              }   
              maxi=max(maxi,pro);
           }else
           {
              gg+=cs;
              cs=0;
              int pro=(gg * bc) - (rc * (i+1));
              cout<<i+1;
              if(pro > maxi){
                   rot=i+1;
              }
           }
          i++;
        }
        
        if(maxi>0) return rot;
        return -1;
        
    }
};