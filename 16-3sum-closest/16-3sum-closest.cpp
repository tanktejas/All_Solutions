class Solution {
public: 
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX;
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            
            int need=target - nums[i];
            int j=i+1;
            int k=n-1;
            
            while(j<k)
            {
                int cs=(nums[j]+nums[k]);
                
                if(abs(need-cs) < abs(1LL*ans - target))
                {
                    ans=cs + nums[i];
                }
                
                if(cs < need)
                {
                    j++;
                }else{
                    k--;
                }
                
            }
            
            
        }
        
        return ans;
    }
};