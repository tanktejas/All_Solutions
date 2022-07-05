class Solution {
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
            // siz[p1]=0;
        }else if(siz[p2] < siz[p1]){
            par[p2]=par[p1];
            siz[p1]+=siz[p2];
            // siz[p2]=0;
        }
    }
     
    int longestConsecutive(vector<int>& nums) {
          int n=nums.size();  
          for(int i=0;i<n;i++){
             
              if(par.find(nums[i])==par.end()){
                par[nums[i]]=nums[i];
                siz[nums[i]]++;
                  
              if(par.find(nums[i]-1)!=par.end()){
                 makeuni(nums[i],nums[i]-1);   
              }     
              if(par.find(nums[i]+1)!=par.end()){
                  makeuni(nums[i],nums[i]+1); 
              } 
          }
       
          }   
        
           int mx=0;
              for(int i=0;i<n;i++){
                  mx=max(mx,siz[nums[i]]);
              }  
      
         return mx;
          
    }
};