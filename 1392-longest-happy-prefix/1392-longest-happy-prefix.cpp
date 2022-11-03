class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        
        vector<int>dp(n+1,0);
        
        int i=1,j=0;
        
        while(i<n)
        {   
           // cout<<i<<' '<<j<<endl;
           if(s[j]==s[i])
            { 
                j++;
                dp[i]=j;
                i++;
            }else if(j!=0)
            { 
               if(j!=0)
                  j=dp[j-1]; 
                
            }else {
               i++;
           }
            
          
            
        }
         
        return s.substr(0,dp[n-1]); 
    }
};