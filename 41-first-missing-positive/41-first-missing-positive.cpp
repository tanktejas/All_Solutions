class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        
        while(i<n)
        {
            int ele=nums[i];
            while(ele<=n and ele>0 and (ele-1)!=i and nums[ele-1]!=nums[i]) 
            {
                swap(nums[ele-1],nums[i]);
                ele=nums[i];
            }
            
            i++;
        }
 
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=(i+1)) return i+1;
        }
        return n+1;
        
    }
};