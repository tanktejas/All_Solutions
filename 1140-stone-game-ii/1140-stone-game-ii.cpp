class Solution {
public:
    vector<vector<int>>dp;
    vector<int>pre;
    
    int find(int n,int idx,int m)
    {
         if(idx>=(n+1)) return 0;
        
         if(dp[idx][m]!=INT_MIN) return dp[idx][m];
         
          int ele=INT_MIN;
        
          for(int i=idx;i<=((idx-1)+2*m);i++)
          { 
              // if(i<n){   
                
                 int picked;
                  if(i<=n)  
                   picked=pre[i]-pre[idx-1];
                 int uu=max(m,(i-idx+1));  
                 int yy=find(n,i+1,uu); 
                if(yy!=INT_MIN and i<=n){
                 
                    int elemax=picked - yy;
                    ele=max(ele,elemax);  
                  
                }
                 
              // }
          }   
         
        return dp[idx][m]=ele;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp.resize(104,vector<int>(104,INT_MIN));
        pre.resize(n+3,0);
        
        pre[1]=piles[0]; 
        int sum=0;
        
        for(int i=1;i<n;i++)
        {  
            pre[i+1]=pre[i]+piles[i];
        
        }
        
        for(int i=0;i<piles.size();i++)
        {
            sum+=piles[i];
        }
        
        return (sum+find(n,1,1))/2;
        
    }
};