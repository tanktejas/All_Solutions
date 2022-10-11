class Solution {
public:
    int min(long long i,int j)
    {
        if(i<j) return i;
        return j;
    }
    
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
          
        long long onec=min(nums[0],nums[1]),onep=nums[0];
        long long twoc,twop=1ll*2*INT_MAX;
        long long threec=1ll*2*INT_MAX,threep=1ll*2*INT_MAX;
        
        for(int i=1;i<n;i++)
        {  
            onec=min(onep,nums[i]);
            twoc=twop;
            threec=threep;
            
            if(onep < nums[i])
            {
                twoc=min(twoc,nums[i]);
            }
            
            if(twop < nums[i])
            { 
                threec=min(threec,nums[i]);
            }      
            
            if(threec != 1ll*2*INT_MAX) return 1;
            
            threep=threec;
            onep=onec;
            twop=twoc;
        }   
        
       return 0;
        
    }
    
};