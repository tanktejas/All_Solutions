class Solution {
public:
    bool isPowerOfFour(int n) {  
        
         if(n<0) return 0;
        
         n=abs(n);
         long long curr=1;
         
         
        
         while(curr<=n)
         {
             if(curr==n) return 1;
             curr*=4;
         }
        
        return 0;
    }
};
