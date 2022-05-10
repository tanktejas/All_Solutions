class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0){
                if(nums[i]==nums[i-1]){
                    continue;
                }
                if(abs(nums[i]-nums[i-1])==1){
                    continue;
                }
            }
            if(i<n-1){
                if(nums[i]==nums[i+1]){
                    continue;
                }
                if(abs(nums[i]-nums[i+1])==1){
                    continue;
                }
            }
           ans.push_back(nums[i]);
        }
        return ans;
    }
};