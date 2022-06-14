class Solution {
public:
    int minimumDeleteSum(string w1, string w2) {
       int s1=w1.size(),s2=w2.size();
        
        vector<vector<int>>v(s1+1,vector<int>(s2+1,0));
      
        for(int i=1;i<=s1;i++){
          for(int j=1;j<=s2;j++){
              if(w1[i-1]==w2[j-1]){
                v[i][j]=w1[i-1] + v[i-1][j-1];
              }else{  
                v[i][j]=max(v[i-1][j],max(v[i][j-1],v[i-1][j-1]));
               }
          }
        }
        
         int sum1=0,sum2=0;
         for(auto x:w1){
             sum1+=x;
         }
          for(auto x:w2){
             sum2+=x;
         }
        return sum1+sum2-2*v[s1][s2];
    }
};