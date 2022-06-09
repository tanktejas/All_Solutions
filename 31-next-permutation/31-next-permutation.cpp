class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sorfrom=-1;
        int n=nums.size();
        
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
               sorfrom=i-1;   
               break;
            }
        }
        
        if(sorfrom==-1){
            sort(nums.begin(),nums.end());
            return ;
        }
        int dd=sorfrom+1;   
        
        while(dd<n and nums[dd]>nums[sorfrom]){
                dd++;
        }
        
        dd--;
        
         swap(nums[dd],nums[sorfrom]);
        
         sort(nums.begin()+sorfrom+1,nums.end());
    }
};