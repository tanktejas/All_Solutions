class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& po, vector<vector<int>>& q) {
          vector<int>ans;
        
          for(int i=0;i<q.size();i++)
          {
             int cnt=0;
              for(int j=0;j<po.size();j++)
              {
                  int val=(abs(q[i][0] - po[j][0])*abs(q[i][0] - po[j][0]))+(abs(q[i][1] - po[j][1])*abs(q[i][1] - po[j][1]));
                  int rads=q[i][2]*q[i][2];
                  
                  if(val <= rads){
                      cnt++;
                  }
              }
              
              ans.push_back(cnt);
          }
        
        return ans;
    }
};