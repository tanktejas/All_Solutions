class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>m;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            
            if(m[nums[i]])
            {
                if(abs(m[nums[i]]-i) <= k) return 1;
            }
            
            if(i!=0 and nums[i]==nums[0] and (i)<=k) return 1;
            
            m[nums[i]]=i;
        }
        
        return 0;
    }
};