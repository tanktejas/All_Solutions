class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>>v(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++) v[i][i]=1;
        
        
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                v[i-1][i]=1;
            } 
        }
        
        for(int i=2;i<n;i++){
            
            int r=0,c=i;
            
            while(c<n){
                if(s[r]==s[c] and v[r+1][c-1]){
                    v[r][c]=1;
                }
                r++;
                c++;
            }
            
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=v[i][j];
            }
        }
        return ans;
    }
};