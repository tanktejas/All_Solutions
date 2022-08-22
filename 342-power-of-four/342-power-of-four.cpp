class Solution {
public:
    bool isPowerOfFour(int n) {  
          if(n<0) return 0;
         if(n==0) return 0;
        
         int ll=log(n)/log(4);
        
         if(pow(4,ll) == n) return 1;
         return 0;
    }
};
