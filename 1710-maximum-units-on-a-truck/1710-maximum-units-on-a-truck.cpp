class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        sort(bt.begin(),bt.end(),[&](vector<int> &a,vector<int> &b){
            return a[1] > b[1];
        });
        
        int ans=0;
        for(int i=0;i<bt.size() and ts;i++){
            if(ts<(bt[i][0])){
                ans+=(ts*bt[i][1]);
                ts=0;
            }else{
                ans+=(bt[i][0]*bt[i][1]);
                ts-=bt[i][0];
            }
        }
        return ans;
    }
};
