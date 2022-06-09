class Solution {
public:
    int maxProfit(vector<int>& pri) {
        int n=pri.size();
        
         vector<int>suf(pri.size());
        int maxi=pri[pri.size()-1];
        int ans=0;
        
        for(int i=pri.size()-1;i>=0;i--){
            maxi=max(maxi,pri[i]);
            ans=max(ans,maxi-pri[i]);
            suf[i]=ans;
        }
        
        vector<int>pre(pri.size());
        int mini=pri[0];
         ans=0;
        
        for(int i=0;i<n;i++){
            mini=min(mini,pri[i]);
            ans=max(ans,pri[i]-mini);
            pre[i]=ans;
        }
        
        ans=0;
        
        for(int i=1;i<n;i++){
            ans=max(ans,pre[i-1]+suf[i]);
        }
        ans=max(ans,max(pre[n-1],suf[0]));
        
        return ans;
    }
};