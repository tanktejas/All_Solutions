class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        vector<int>pre(n,0),suf(n,0);
        pre[0]=c[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+c[i];
        }
        suf[n-1]=c[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+c[i];
        }
        
        int ans=max(suf[n-k],pre[k-1]);
        int i=0,j=n-k+1;   
        while(j<n){
            int curr=pre[i]+suf[j];
            ans=max(ans,curr);
            i++;
            j++;
        } 
        return ans;
    }
};