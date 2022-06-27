class Solution {
public:
    int dp[101][101][2];
    int countSubstrings(string s, string t) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j][0]=0;
                dp[i][j][1]=0;
            }
        }
        int n=s.length(),m=t.length();
        
        int cnt=0;
        
        for(int i=1;i<m;i++){
            if(s[0]==t[i]){
                dp[0][i][0]=1;
                dp[0][i][1]=0;
            }else{
                dp[0][i][0]=0;
                dp[0][i][1]=1;   
            }
            cnt+=dp[0][i][1];
        }
        
        for(int i=0;i<n;i++){
            if(s[i]==t[0]){
                dp[i][0][0]=1;
                dp[i][0][1]=0;
            }else{
                dp[i][0][0]=0;
                dp[i][0][1]=1;   
            }
            cnt+=dp[i][0][1];
        }
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                
                if(s[i]==t[j]){
                    dp[i][j][0]=1 + dp[i-1][j-1][0];
                    dp[i][j][1]=dp[i-1][j-1][1]; 
                }else{
                    dp[i][j][0]=0;
                    dp[i][j][1]=1 + dp[i-1][j-1][0];  
                }            
                
                cnt+=dp[i][j][1];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j][1]<<" ";
            }
            cout<<endl;
        } 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j][0]<<" ";
            }
            cout<<endl;
        } 
        // if(s[0]!=t[0]) cnt--;
        
        return cnt;
        
        //dp part start
        // if same charator found
        //  => dp[i][j][0] => dp[i-1][j-1][0] + 1;
        //  => dp[i][j][1] => dp[i-1][j-1][1];
        // if diffrent charactor found
        //  => dp[i][j][0] => 0
        //  => dp[i][j][1] => 1 + dp[i-1][j-1][0];
        
    }
};