class Solution {
public:
    int reinitializePermutation(int n) {
         vector<int>curr(n);
        
         for(int i=0;i<n;i++)
         {
           curr[i]=i;
         }
        
         vector<int>tmp;
         int op=0;
        
         for(int i=0;i<n;i++){
             
             tmp.clear();
             tmp.resize(n);
             
             for(int j=0;j<n;j++){
                 if(j&1){
                     int kk=((n/2)+((j-1))/2);
                     tmp[j]=curr[kk]; 
                 }else{
                     int kk=(j/2);
                     tmp[j]=curr[kk];  
                 }
                 
             }
             
             curr=tmp;
             
             // for(int i=0;i<n;i++) cout<<tmp[i]<<" ";
             // cout<<endl;
             
             int bo=1;
             for(int k=0;k<n;k++){
                 if(curr[k]!=k) bo=0;
             }
             
             if(bo) return i+1;
             
         }
        
        return 1;
    }
}; 

