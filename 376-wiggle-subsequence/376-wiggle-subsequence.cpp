class Solution {
public:
    int dp[1001][2];
    int wiggleMaxLength(vector<int>& nums) {
//         memset(dp,-1,sizeof(dp));
//         int n=nums.size();
        
//         dp[n-1][0]=1;
//         dp[n-1][1]=1;
        
//         for(int i=n-2;i>=0;i--){
//             int cp=nums[i];
//             int dm=0,im=0;
//             for(int j=i+1;j<n;j++){
//                 if(nums[j]>nums[i]){
//                     dm=max(dm,dp[j][1]);
//                 }else if(nums[j]<nums[i]){
//                     im=max(im,dp[j][0]);
//                 }
//             }
//             dp[i][0]=1+dm;
//             dp[i][1]=1+im;
        
//         }
        
       
        // return max(dp[0][0],dp[0][1]);
        
          int size=nums.size(), peak=1, valley=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) peak = valley + 1;
            else if(nums[i]<nums[i-1]) valley = peak + 1;
        }
        
        return max(peak , valley );
        
    }
};     