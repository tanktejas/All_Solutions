class Solution {
public:
    vector<int> find(string s)
    {
        int n=s.length();
        vector<int>ans(n);
        int j=0;
        
        for(int i=1;i<n;i++)
        {
            while(j>0 and s[i]!=s[j]) j=ans[j-1];
            
            if(s[i]==s[j]){
                j++;
            }
            
            ans[i]=j;
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<' ';
        
        return ans;
    }
    
    string shortestPalindrome(string s) {
        if(s=="") return "";
        
        
        string gg=s;
        int n=s.length();
        string aa=s;
        reverse(s.begin(),s.end());
        aa=aa+"#"+s;
        
        vector<int>dd=find(aa);
        int start= dd[(2*n)];
       
        if(start==((2*n)-1)) return gg;
        // cout<<start;
         
        string hh=gg.substr(start);
        reverse(hh.begin(),hh.end());
        
        return hh + gg;        
        
    }
};