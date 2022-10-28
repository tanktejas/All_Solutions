class Solution {
public:
    int minimumTime(string s) {
        int n=s.length();
        
        vector<int>pre(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
           int fop=i,sop=pre[i-1]+((s[i-1]-'0')*2);
           pre[i]=min(fop,sop); 
        }
        
        int ans=pre[n];
        int pmin=0;
        
        for(int i=n;i>=1;i--)
        {
            int fop=n-i+1,sop=pmin+((s[i-1]-'0')*2);
            ans=min(ans,pre[i-1]+min(fop,sop));
            pmin=min(fop,sop);
        }
        
        return ans;
        
    }
};