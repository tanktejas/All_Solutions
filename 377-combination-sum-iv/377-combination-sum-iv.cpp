class Solution {
public:
    vector<int>dp;
    vector<int>arr;
    
    int find(int n)
    { 
        
        if(n==0) return 1;
        if(n<0) return 0;
         
        if(dp[n]!=-1) return dp[n];
        int wa=0;
        
        for(int i=0;i<arr.size();i++)
        {
            wa+=find(n-arr[i]);
        }     
       return dp[n]=wa;
    
    }        

    int combinationSum4(vector<int>& nums, int tar) {
        int n=nums.size();
        arr=nums;
        dp.resize(tar+1,-1);
        
        sort(nums.begin(),nums.end());
        
        int ele= find(tar); 
         
        return ele;
    }      
};