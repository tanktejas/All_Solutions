class Solution {
public: 
    long long countExcellentPairs(vector<int>& nums, int k) { 
        vector<long long>stbit(74,0);
        
        sort(nums.begin(),nums.end());
        map<int,int>m;
        
        for(int i=0;i<nums.size();i++)
        {
            
         if(m[nums[i]]==0){   
          int sb=__builtin_popcount(nums[i]);
          stbit[sb]++;
          m[nums[i]]=1;
         }
        }
        
        long long cnt=0;
        
        
        // for(int i=0;i<n;i++) cout<<stbit[i]<<" ";
        
        for(int i=0;i<=31;i++)
        {
            
            for(int j=0;j<=31;j++)
            {
                if((i+j) >= k)
                {
                    cnt+=(1LL * stbit[i] * stbit[j]);
                }
            }
            
            
        }
        
        
        return cnt;
    }
};  