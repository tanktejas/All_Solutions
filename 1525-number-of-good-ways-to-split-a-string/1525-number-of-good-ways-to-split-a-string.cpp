class Solution {
public:
    int numSplits(string s) {
        int n=s.length();
        
        vector<int>suf(n+1,0);
        unordered_map<int,int>m;
        
        for(int i=n-1;i>=0;i--)
        {
            suf[i]=suf[i+1];
            if(m[s[i]]==0)
            {
                suf[i]++;
            }
            m[s[i]]++;
        }
        
        int auni=0;
        m.clear();
        int ans=0;
        
        for(int i=0;i<n;i++)
        { 
            if(m[s[i]]==0)
            {
                auni++;
            }
            m[s[i]]++;  
            
            if(auni == suf[i+1])
            {
                ans++;
            }
        }
        
        return ans;
    }
};