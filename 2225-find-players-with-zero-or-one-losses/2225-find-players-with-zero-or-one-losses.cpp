class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& ma) {
        vector<int>ind(100001,-1);
        vector<vector<int>>ans(2);
        for(int i=0;i<ma.size();i++){
        
             if(ind[ma[i][1]] == 0 or ind[ma[i][1]] == -1){
                 ind[ma[i][1]]=1;
             }else{
                 ind[ma[i][1]]++;
             }
            if(ind[ma[i][0]]==-1){
                ind[ma[i][0]]=0;
            }
        }
        for(int i=0;i<=100000;i++){
            if(ind[i]==0) ans[0].push_back(i);
            else if(ind[i]==1) ans[1].push_back(i);
        } 
        return ans;
    }
};