class Solution {    
public:
    bool checkPossibility(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int prevabs=INT_MIN;
        
        int ml=0;
        
        for(int i=2;i<n;i++){
            if(nums[i] < nums[i-1]) ml++; 
        }
        
        int mr=0;
        
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
               mr++;
            }
        }
        
        if(!mr or !ml) return 1;
         
        for(int i=1;i<n-1;i++){
           if(nums[i]<nums[i-1] or nums[i]>nums[i+1]){
    
               if(nums[i-1] > nums[i+1]){
                   if(nums[i]<nums[i-1]) return 0;
                   else{
                       nums[i+1]=nums[i];
                       ans++;
                   }
               }else{
                   nums[i]=nums[i-1];
                   ans++;
               }
           }
        }
        
        return ans<=1;
    }
};