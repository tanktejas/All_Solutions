class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
   
      int n=nums.size();
      vector<int>v;
        
      for(int i=0;i<n;i++)
      {
         auto low=lower_bound(v.begin(),v.end(),nums[i]);
         
         if(low == v.end()){
             v.push_back(nums[i]);
         }else{
             int idx=low - v.begin();
             swap(nums[i],v[idx]);
         }
      }
        
        return v.size();
    }
};