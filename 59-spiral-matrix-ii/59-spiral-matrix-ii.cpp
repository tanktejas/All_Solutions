class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       int val=1;
       vector<vector<int>>ans(n,vector<int>(n,0));
       int cols=0,cole=n-1,rows=0,rowe=n-1;
       while(rows<=rowe){
          for(int i=cols;i<=cole;i++){
              ans[rows][i]=val;
              val++;
          }
           rows++;
           for(int i=rows;i<=rowe;i++){
               ans[i][cole]=val;
               val++;
           }
           cole--;
           for(int i=cole;i>=cols;i--){
               ans[rowe][i]=val;
               val++;
           }
           rowe--;
           for(int i=rowe;i>=rows;i--){
               ans[i][cols]=val;
               val++;
           }
           cols++;           
       }
    return ans;
    }
};