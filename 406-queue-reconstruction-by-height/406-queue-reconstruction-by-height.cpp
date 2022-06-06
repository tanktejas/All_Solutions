    bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }

class Solution {
public:
    

    vector<vector<int>> reconstructQueue(vector<vector<int>>& pe) {
        
        sort(pe.begin(),pe.end(),cmp);
        
        int n=pe.size();
        
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
              res.insert(res.begin()+pe[i][1],pe[i]); 
        }
        
        
        return res;
    }
};