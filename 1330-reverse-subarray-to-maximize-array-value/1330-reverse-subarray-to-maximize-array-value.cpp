class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int fmax=INT_MIN,fmin=INT_MAX;
        int n=nums.size();
        int tt=0;
        
        for(int i=0;i<n-1;i++)
        {
            tt+=(abs(nums[i]-nums[i+1]));
        }
            
        for(int i=0;i<n-1;i++)
        {
            fmax=max(fmax, min(nums[i],nums[i+1]));
            fmin=min(fmin, max(nums[i],nums[i+1]));
        }
        
        int diff=2*(fmax - fmin);
        
        
        for(int i=1;i<n;i++)
        {  
             diff=max(diff,abs(nums[0]-nums[i])-abs(nums[i]-nums[i-1]));   
        }
       
        for(int i=0;i<n-1;i++)
        {    
             diff=max(diff,abs(nums[n-1]-nums[i])-abs(nums[i]-nums[i+1])); 
        }
        
        return tt + diff;
    }
};