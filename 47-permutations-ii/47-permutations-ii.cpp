class Solution {
public:
        void find(vector<int> &nums,vector<vector<int>> &v,int st,map<vector<int>,int> &s){
        if(st==nums.size()){
            if(!s[nums]){
             s[nums]=1;
            v.push_back(nums);
            }
            return;
        }      
        for(int i=st;i<nums.size();i++){
            swap(nums[i],nums[st]); 
            find(nums,v,st+1,s);  
            swap(nums[i],nums[st]);
        }  
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     map<vector<int>,int>s;
        vector<vector<int>>v;
        find(nums,v,0,s);
    return v;
    }
};