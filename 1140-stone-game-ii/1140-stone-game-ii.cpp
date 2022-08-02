class Solution {
public:
    vector<vector<int>>dp;
    vector<int>pre;
    
    int find(int n,int idx,int m)
    {
         if(idx>pre.size()) return 0;
        
         if(dp[idx][m]!=-1) return dp[idx][m];
        
          int ele=INT_MIN;
          int tot=0;
        
          for(int i=0;i<2*m;i++)
          { 
              if((i+idx)<pre.size()) tot+=pre[idx+i]; 
                 int elemax=tot - find(n,idx+i+1,max(m,i+1)); 
                 ele=max(ele,elemax);  
          }
         
        return dp[idx][m]=ele;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp.resize(104,vector<int>(104,-1));
        pre=piles;
        
//         pre[1]=piles[0]; 
        int sum=0;
        
//         for(int i=1;i<n;i++)
//         {  
//             pre[i+1]=pre[i]+piles[i];
        
//         }
        
        for(int i=0;i<piles.size();i++)
        {
            sum+=piles[i];
        }
        
        return (sum+find(n,0,1))/2;
        
    }
};