class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int> &v,int n,int k,int s){
        
        
        if(v.size()==k and n==0){
            ans.push_back(v);
            return ;
        }
        
        if(n<=0 or v.size()==k) return ; 
        
        for(int i=s;i<=9;i++){
            v.push_back(i);
            solve(v,n-i,k,i+1);
            v.pop_back();
        }
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        solve(v,n,k,1);
        return ans;
    }
};