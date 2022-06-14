class Solution {
public:
    int minDistance(string w1, string w2) {
        int s1=w1.size(),s2=w2.size();
        
        vector<vector<int>>v(s1+1,vector<int>(s2+1,0));
      
        for(int i=1;i<=s1;i++){
          for(int j=1;j<=s2;j++){
              if(w1[i-1]==w2[j-1]){
                v[i][j]=1+v[i-1][j-1];
              }else{
                v[i][j]=max(v[i-1][j],max(v[i][j-1],v[i-1][j-1]));
               }
          }
        }
        
        return s1+s2-2*v[s1][s2];
    }
};