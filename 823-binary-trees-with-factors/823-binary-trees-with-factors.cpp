class Solution {
public:
    int mod=1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        
        for(int i=1;i<n;i++)
        {
            int f=0,e=i-1;
           unsigned long long tar=nums[i];
            
            while(f<=e)
            { 
               unsigned long long pro=1LL*nums[f]*nums[e];
                
                if(pro==tar){
                    
                    dp[i]=(dp[i] + (1LL*dp[f]*dp[e]))%mod;
                
                    if(f!=e){
                        dp[i]=(dp[i] + (1LL*dp[f]*dp[e]))%mod;
                    }
                    
                    f++;
                    e--;
                }else if(pro<tar)
                {
                    f++;
                }else{
                    e--;
                }
            }
            
        }
        
        int ans=0;
       
        for(int i=0;i<n;i++){
            ans= (ans + dp[i])%mod;
        }
        
        return ans;
    }
};