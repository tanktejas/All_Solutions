class Solution {
public:
    int deleteString(string s) {
        
        int n=s.length();
        
        vector<int>dp(n+1,0);  
        string cur="";   
        
        vector<vector<int>>lcs(n+1,vector<int>(n+1,0));
        
        dp[n-1]=1;
        
        for(int i=n-2;i>=0;i--)
        {  
             string cur="";
             string h=""; 
             
             for(int j=i;j<n;j++)
             { 
                 if(s[i]==s[j])
                 {
                     lcs[i][j]=lcs[i+1][j+1] + 1;    
                 }
                 
                 if(lcs[i][j] >= (j-i))
                 {
                     dp[i]=max(dp[i],dp[j]+1);
                 }
             }
        }
         
        
       return dp[0];
    }
};