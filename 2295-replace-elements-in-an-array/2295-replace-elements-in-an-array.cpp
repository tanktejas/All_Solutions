class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
         unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
             m[nums[i]]=i;
        }
        
        for(int i=0;i<op.size();i++){
            int find=op[i][0];
            int idx=m[find];
            m[op[i][0]]=-1;
            m[op[i][1]]=idx;
            nums[idx]=op[i][1];
        }
        
        return nums;
    }
};