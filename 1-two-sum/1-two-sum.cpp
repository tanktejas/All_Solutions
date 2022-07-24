class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m; 
        // sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {   
            if(target - nums[i] == nums[0] and i!=0) return {0, i};
            
            if(m[target - nums[i]]){
                return {i,m[target - nums[i]]};
            } 
            
            m[nums[i]]=i;
        } 
        
        return {};
    }
};   