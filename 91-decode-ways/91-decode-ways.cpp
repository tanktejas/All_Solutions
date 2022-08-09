class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        
        vector<int>dp(n+1,0); 
        if(s[0]!='0') dp[1]=1;
        dp[0]=1;
         
        for(int i=2;i<=n;i++)
        {
            int idx=i-1;
            
            if(s[idx]=='0'){
                if(s[idx-1]>='1' and s[idx-1]<='2'){
                    dp[i]=dp[i-2];
                }
            }else{
                if(s[idx-1]=='0'){
                    dp[i]=dp[i-1];
                }else{
                    dp[i]=dp[i-1];
                    string gg="";
                    gg+=s[idx-1];
                    gg+=s[idx];
                    
                    int ii=stoi(gg);
                    
                    if(ii>=1 and ii<=26){
                        dp[i]+=dp[i-2];
                    }
                }
            }
        } 
        return dp[n];
    }
};
