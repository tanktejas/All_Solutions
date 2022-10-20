class Solution {
public:
    vector<vector<long long>>pascal;
    int mod=1e9+7;
    
    int find(vector<int> nums)
    {
        vector<int>left,right;
        int n=nums.size();
        
        if(n<=2)
        {
            return 1;
        }
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[0])
            {
                left.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            }
        }
        
        int lsiz=left.size();
        
        int l=find(left);
        int r=find(right);
         
        return (((pascal[n-1][lsiz] * l)%mod)* r )%mod;
        
    }
    
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        
        pascal.resize(n+1);
        
        for(int i=0;i<=n;i++)
        {   
            pascal[i]=vector<long long>(i+1,1);
            for(int j=1;j<i;j++)
            {
                pascal[i][j]=(pascal[i-1][j-1] + pascal[i-1][j])%mod;
            }
            
        }
        
        return find(nums) - 1;
        
    }
};