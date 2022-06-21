class Solution {
public:  
    int furthestBuilding(vector<int>& h, int br, int la){
        priority_queue<int,vector<int>,greater<int>>q;
        int fur=0;
        int sum=0; 
        int skip=0;
        int n=h.size();
        int i;
        for(i=0;i<n-1;i++){
            int cd=h[i+1]-h[i];
            if(cd<=0){
                fur=i+1;
                continue;
            }else{
               if(q.size()<la){
                   fur=i+1;
                   q.push(cd);
               }else{
                   q.push(cd);
                   int tt=q.top();
                   q.pop();
                   sum+=tt;
                   if(sum<=br){
                       fur=i+1;  
                   }else{
                       break;
                   }
               } 
            }
             
        }
        
        if(i==n-1) return n-1;
        return fur;
    }
};