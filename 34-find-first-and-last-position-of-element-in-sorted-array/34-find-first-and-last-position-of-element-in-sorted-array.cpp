class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
      
         int f=-1,s=-1;
         int i=0,j=nums.size()-1;
        
        
        while(i<=j)
        {  
            int mid=(i+j)/2;
            
            if(nums[mid]==target){
                f=mid; 
            }
            
            if(nums[mid] < target) i=mid+1;
            else j=mid-1;
        }
        
        
        
         i=0,j=nums.size()-1;
        
         while(i<=j)
        {  
            int mid=(i+j)/2;
            
            if(nums[mid]==target){
                s=mid; 
            }
            
            if(nums[mid] > target) j=mid-1;
            else i=mid+1;
        }
        
        return {f,s};
         
    }
};