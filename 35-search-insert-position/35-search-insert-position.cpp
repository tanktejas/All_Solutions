class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
//         int i=0,j=nums.size()-1;
//         while(i<=j)
//         {  
//             int mid=(i+j)/2;
            
//             if(nums[mid]==target) return mid;
            
//             if(nums[mid] < target) i=mid+1;
//             else j=mid-1;
//         }
        
//         return i;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target) return i;
            if(nums[i] > target) return i;
        }
        return nums.size();
    }
};

