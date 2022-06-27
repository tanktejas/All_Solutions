class Solution {
public:
    vector<long long>dp;
    
    long long find(int st,vector<vector<int>> &qu){
        if(st>=qu.size()) return 0;
        
        if(dp[st]!=-1) return dp[st];
        
        return dp[st]=max(qu[st][0] + find(st+qu[st][1]+1,qu),find(st+1,qu));
    }
    
    long long mostPoints(vector<vector<int>>& qu) {
         int n=qu.size();
         dp.resize(n+1,-1);
         return find(0,qu);
    }
};
