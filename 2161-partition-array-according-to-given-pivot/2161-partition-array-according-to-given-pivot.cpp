class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int x) {
         vector<int>ans;
         int i=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<x){
                ans.push_back(nums[i]);
            }
        }
         for(int i=0;i<n;i++){
            if(nums[i]==x){
                ans.push_back(nums[i]);
            }
        }
         for(int i=0;i<n;i++){
            if(nums[i]>x){
                ans.push_back(nums[i]);
            }
        }
        
       return ans;
    }
};