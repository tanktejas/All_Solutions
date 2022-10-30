class Solution {
public:
    
    bool chk(vector<int> &a,long long mid,int k)
    {
        int n=a.size();
        for(int i=0;i<n;i++)
        {
          if(k>0)
            k-=(1ll*mid/a[i]);
        }
        return k<=0;
    }
    
    long long minimumTime(vector<int>& nums, int t) {
        
        int mini=INT_MAX;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            mini=min(mini,nums[i]);
        }
        
        long long j=1ll*mini*t;
        long long i=0;
        
        long long ans=j;
        
        while(i<=j)
        {
            long long mid=(1ll*i+j)/2;
             
            if(chk(nums,mid,t))
            {
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        
        return ans;
    }
};