class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mx=INT_MIN;
        
        for(int i=0;i<n-2;i++)
        {
            int f=nums[i],s=nums[i+1],t=nums[i+2];
            
            if(t < (f+s) and s < (f+t) and f < (s+t))
            {
                mx=max(mx,f+s+t);
            }
        }
        
        if(mx==INT_MIN) return 0;
        else return mx;
         
    }
};