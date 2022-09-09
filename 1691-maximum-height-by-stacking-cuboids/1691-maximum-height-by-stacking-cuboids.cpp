class Solution {
public:
    
    int maxHeight(vector<vector<int>>& c) {
        for(auto &ele:c)
        {
            sort(ele.begin(),ele.end());
        } 
        
        sort(c.begin(),c.end());
        
        int n=c.size();
        vector<int>dp(n,-1);
        
        dp[0]=c[0][2];  
        
        for(int i=1;i<n;i++){
             
            int maxi=c[i][2];  
            for(int j=0;j<i;j++){
                
                if((c[j][1] <= c[i][1] and c[j][2] <= c[i][2])){
                    maxi=max(c[i][2]+dp[j],maxi);
                }  
                 
            }
            dp[i]=maxi; 
        }  
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){ 
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};