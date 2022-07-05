
  
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
    
    int longestConsecutive(vector<int>& nums) {
          int n=nums.size();  
          DSU obj;
        
          for(int i=0;i<n;i++){
             
              if(obj.par.find(nums[i])==obj.par.end()){
                  
                obj.par[nums[i]]=nums[i];
                obj.siz[nums[i]]++;
                  
              if(obj.par.find(nums[i]-1)!=obj.par.end()){
                 obj.makeuni(nums[i],nums[i]-1);   
              }     
              if(obj.par.find(nums[i]+1)!=obj.par.end()){
                  obj.makeuni(nums[i],nums[i]+1); 
              }
                  
           }
       
          }   
        
           int mx=0;
              for(int i=0;i<n;i++){
                  mx=max(mx,obj.siz[nums[i]]);
              }  
      
         return mx;
          
    }
};

 