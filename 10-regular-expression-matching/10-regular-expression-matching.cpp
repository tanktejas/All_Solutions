class Solution {
public:
    bool isMatch(string s, string p) {
          int match=0;
        int sl=s.length();
        int pl=p.length();
        
        vector<vector<int>>v(pl+1,vector<int>(sl+1,0));
       
          v[0][0]=1;
        
        for(int i=1;i<=pl;i++){
           if(p[i-1]=='*' and v[i-2][0]){
               v[i][0]=1;
           }  
        }
         
        for(int i=1;i<=pl;i++)
        {
            for(int j=1;j<=sl;j++)
            {
                int mati=i,matj=j;
                 
                if(p[i-1]==s[j-1] or p[i-1]=='.'){
                    v[mati][matj]=v[mati-1][matj-1];
                }else if(p[i-1]=='*'){    
                     v[i][j]=v[i-2][j];
                    if(s[j-1]==p[i-2] or p[i-2]=='.'){   
                        v[i][j]=v[i][j-1] or v[i][j]; 
                    }      
                    
                } 
            }
        }
        
        for(int i=0;i<=pl;i++)
        {
            for(int j=0;j<=sl;j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return v[pl][sl];
    }
};

// class Solution {
// public:
//     bool isMatch(string str, string pat) {
        
//         int n = str.size();
        
//         int m = pat.size();
        
//         vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        
//         for(int i = 0; i <= m; i++)
//         {
//             for(int j = 0; j <= n; j++)
//             {
//                 if(i == 0 && j == 0)
//                 {
//                     dp[i][j] = true;
//                 }
                
//                 else if(i == 0)
//                 {
//                     dp[i][j] = false;
//                 }
                
//                 else if(j == 0)
//                 {
//                     if(pat[i - 1] == '*')
//                     {
//                         dp[i][j] = dp[i - 2][j];
//                     }
                    
//                     else
//                     {
//                         dp[i][j] = false;
//                     }
//                 } 
//                 else
//                 {
//                     if(pat[i - 1] == '*')
//                     {
//                         dp[i][j] = dp[i - 2][j]; 

//                         if(pat[i - 2] == '.' || pat[i - 2] == str[j - 1])
//                         {
//                             dp[i][j] = dp[i][j] || dp[i][j - 1];
//                         }
//                     }
                    
//                     else if(pat[i - 1] == '.')
//                     {
//                         dp[i][j] = dp[i - 1][j - 1];
//                     }
                    
//                     else if(pat[i - 1] == str[j - 1])
//                     {
//                         dp[i][j] = dp[i - 1][j - 1];
//                     }
                    
//                     else
//                     {
//                         dp[i][j] = false;
//                     }
//                 }
//             }
//         }
        
//             for(int i=0;i<=pat.length();i++)
//         {
//             for(int j=0;j<=str.length();j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//         return dp[m][n];
//     }
// };