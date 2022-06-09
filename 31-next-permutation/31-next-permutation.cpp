class Solution {
public:
    //intution :-  
    
    // first i have to find first pair from last such that nums[i]<nums[i+1] because that is the inversion and all from i+1, i+2 .... n which is last greater element that swapped with i th element so we optimally find what comes at ith place. now i have fixed i th place all i need to do is sort i+1 to n element in array because i have found new value at ith place so sort is necessary.
    
    //example : 
    
    // 7 5 8 7 6 4.
    
    // here (5, 8) is last inversion pair so we find as much greater element then 5 whcih take place of 5 but notice that element never be greater than 8 because we have chossen last inversion pair so we cannot find any pair after i such that nums[i] < nums[i+1].
    
    // 7 6 sort(8, 7, 5, 4);
    
    // 7 6 4 5 7 8. that is the next permutation.
    
    
    
    
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