class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        nums.resize(n+1);
        nums[n]=-1;
        for(int i=0;i<n+1;i++){
             if(nums[i]!=i){
                 // swap(nums[i],nums[nums[i]]);
                 while(i!=-1 and nums[i]!=-1 and i!=nums[i]){
                     swap(nums[i],nums[nums[i]]);
                 }
             }
        }
        for(int i=0;i<n+1;i++) cout<<nums[i]<<" ";
        cout<<endl;
        for(int i=0;i<n+1;i++){
            if(nums[i]!=i){
                return i;
            }
        }
        
        return n+1;
    }
};