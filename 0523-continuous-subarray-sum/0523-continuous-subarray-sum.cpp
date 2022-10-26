class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
          map<int,int>m;
         int n=nums.size();
        
         int sm=0;
         
         m[0]=-1;   
        
         
         for(int i=0;i<n;i++)
         {
             sm+=nums[i];
             
             if(m.count(sm%k))
             {
                 if((i - m[sm%k]) > 1)
                 {
                     return 1;
                 }
             }else{
                 m[sm%k]=i;    
             }
             
         } 
         
         
        return 0;
    }
};