class Solution {
public:
    int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}
    
    
    int minOperations(vector<int>& nums, vector<int>& nd) {
        sort(nums.begin(),nums.end());
     
        int i=0;
        
        int gg=nd[0];
        
        for(int i=1;i<nd.size();i++){
            gg=gcd(gg,nd[i]);
        }
        
        cout<<gg<<endl;
        
        for(int i=0;i<nums.size();i++)
        {   
            if((gg%nums[i])==0) return i; 
        }
        
        return -1;
    }
};