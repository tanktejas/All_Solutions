class Solution {
public:
    long long maximumSubsequenceCount(string t, string p) {
        string dd="";
        long long n=t.length();
        string s=t;
        for(int i=0;i<n;i++)
        {
            if(s[i]==p[0] or s[i]==p[1]) dd+=s[i]; 
        }
         
        n=dd.length(); 
        vector<int>suff(n,0);
        
        if(dd=="") return 0;
        
        if(dd[n-1]==p[1]) suff[n-1]=1; 
        
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=(suff[i+1] + (dd[i]==p[1]));
        } 
        
        long long ans=0;
        int pc=0;  
        
        for(int i=0;i<n;i++)
        {
            if(dd[i]==p[0]){
               ans+=suff[i];
            }else{
                ans+=pc;
            }
            pc+=(dd[i]==p[0]);
            
        }  
        ans=ans/2;
        
        long long hh=(1LL*n*(n-1))/2;
        if(p[0]==p[1]) ans=hh;
        
        ans+=(max(suff[0],pc));
        
        return ans;
    }
};
