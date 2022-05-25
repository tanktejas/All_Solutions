class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) { 
       vector<int>dp;
        sort(en.begin(),en.end(),[](vector<int>&a,vector<int>&b){ return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);});
       for(auto &pair:en){ 
           auto itr=lower_bound(dp.begin(),dp.end(),pair[1]);
           if(itr==dp.end()) dp.push_back(pair[1]);
           else if(*itr>pair[1])*itr=pair[1];
       } 
       return dp.size(); 
    }
};