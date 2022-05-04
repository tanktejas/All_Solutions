class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m[k-nums[i]]){
                m[k-nums[i]]--;
                ans++;
            }else{
                m[nums[i]]++;
            }
        }
        return ans;
    }
};