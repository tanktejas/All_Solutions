class Solution {
public:
    string f,s,t;
    int dp[101][101]; 
        
    bool find(int i,int j,int k){
        if(k==t.length()) return 1;
        
        if(i==f.length()){
            return s.substr(j)==t.substr(k);
        }
        if(j==s.length()){
            return f.substr(i)==t.substr(k);
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j]=0;
        
        if(f[i]==t[k] and s[j]!=t[k]){
            dp[i][j]=find(i+1,j,k+1);
        }else if(s[j]==t[k] and f[i]!=t[k]){
            dp[i][j]=find(i,j+1,k+1);
        }else if(f[i]==t[k] and s[j]==t[k]){
            dp[i][j]=find(i+1,j,k+1) or find(i,j+1,k+1);
        }
       
        return dp[i][j];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.length()+s2.length())!=s3.length()) return 0;
        memset(dp,-1,sizeof(dp));
        
        f=s1;
        s=s2;
        t=s3;
         
       return find(0,0,0);
    }
};

 