class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int ans=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                i++;
                j--;
                ans++;
            }else if(nums[i]+nums[j]<k){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};