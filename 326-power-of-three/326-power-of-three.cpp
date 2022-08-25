class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<=0) return 0;
        
        int ll=ceil(log(n)/log(3)); 
        cout<<ll;
        
        if(pow(3,ll)==n) return 1;
        
            return 0;
        
    }
};