class Solution {
public:
    vector<vector<int>>dp;
    
    int find(int idx,int maxa,int n,vector<pair<int,int>> &p){
        if(idx>=n){
            return 0;
        }
    
       
        if(dp[idx][maxa]!=-1){
            return dp[idx][maxa];
        }
         int pick=0,notpick=0;
     if(p[idx].second>=maxa){  
            pick=p[idx].first + find(idx+1,p[idx].second,n,p);
     }
        
      notpick=find(idx+1,maxa,n,p);
    
      return  dp[idx][maxa]=max(pick,notpick);
    }
    int bestTeamScore(vector<int>& sco, vector<int>& ag) {
        vector<pair<int,int>>p;
        int n=sco.size();
        for(int i=0;i<n;i++){
            p.push_back(make_pair(sco[i],ag[i]));
        }
        sort(p.begin(),p.end());
        
        dp=vector<vector<int>>(1005,vector<int>(1005,-1));
        
        int val= find(0,0,n,p); 
         
      return val;
    }
};