class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long s=0;
        long long curr=0;
        int maxfreq=1;
     for(int e=1;e<nums.size();e++){
           long long diff=nums[e]-nums[e-1];
           curr+=(e-s)*(diff);
         
            while(s<e and curr>k){
                curr-=(nums[e]-nums[s]);
                s++;
            }    
            
           if(curr<=k)
              if(e-s+1 > maxfreq){
                  maxfreq=e-s+1;
              }
        }
        return maxfreq;
    }
};