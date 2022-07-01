class Solution {
public:
    
     
    int countPrimes(int n) {
       // if(n==0) return 0;
            int c=0;
     vector<long long>se(n,1);
        for(long long i=2;i<n;i++){ 
            if(se[i]==1){
                c++;
              for(long long j=i*i;j<n;j+=i){
                se[j]=0;
             }
           }
        }  
        
    
       return c;
    }
};