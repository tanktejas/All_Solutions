class Solution {
public:
    int maxProfit(vector<int>& pri) {
        int maxi=pri[pri.size()-1];
        int ans=0;
        
        for(int i=pri.size()-1;i>=0;i--){
            maxi=max(maxi,pri[i]);
            ans=max(ans,maxi-pri[i]);
        }
        
        return ans;
    }
};