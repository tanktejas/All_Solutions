class Solution {
public:
    int concatenatedBinary(int n) {
        int pp=1;
        int ans=0;
        int mod=1e9 + 7;
        
        for(int i=n;i>=1;i--)
        {
            int ele=i;
            while(ele>0)
            {
                int mood=ele%2;
                if(mood)
                {
                    ans=(ans + (pp)%mod)%mod; 
                }
                pp=(pp*2)%mod;
                ele/=2;
            }
        }
        return ans;
    }
};