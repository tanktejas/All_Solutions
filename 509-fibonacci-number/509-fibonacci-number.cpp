class Solution {
public:
    int fib(int n) {
        if(n==0 or n==1) return n;
        n-=1;
        int f=0,s=1,c;    
        while(n>0){
            c=f+s;
            f=s;
            s=c;
            n--;
        }  
        return c;
    }
};


