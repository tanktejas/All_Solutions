class Solution {
public:
      
//     int dp[501][501]; 
//     int vis[501][501];
//     int dx[4]={0,-1,0,1};
//     int dy[4]={-1,0,1,0};
//     int mod=1000000007;
//     int nn,mm;
    
//     bool is(int i,int j) return i>=0 and i<nn and j>=0 and j<nn and !vis[i][j];
    
    
//     int find(int i,int j){
          
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int way=0;
        
//         for(int k=0;k<4;k++){
//             int nx=i + dx[k];
//             int ny=j + dy[k];
//              if(is(nx,ny))
//               way=(way + find(nx,ny,rm-1)); 
 
//         }
          
//         return dp[i][j]=(way);
        
//     }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
       // nn=n,mm=n; 
       
       int len=s.length();
       vector<int>ans(len);
        
        for(int i=0;i<len;i++){
            
            int st=startPos[0],e=startPos[1];
            int cnt=0;
            int sp=i;
            for(int k=i;k<len;k++){
                if(s[k] == 'U'){
                    st-=1;
                }
                if(s[k] == 'D'){
                    st+=1; 
                }
                if(s[k] == 'L'){
                    e-=1;
                }
                if(s[k] == 'R'){
                    e+=1;
                }
                
                if(st<0 or st>=n or e<0 or e>=n) break;
                
                cnt++;
            }
            
            ans[i]=cnt;
        }
        
        return ans;
        
    }
};