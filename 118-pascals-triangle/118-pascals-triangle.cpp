class Solution {
public:
    vector<vector<int>> generate(int nr) {
        if(nr==1) return {{1}};
        else if(nr==2) return {{1},{1,1}};
         vector<vector<int>>v(nr);
         v[0].push_back(1);
         v[1].push_back(1);
          v[1].push_back(1);
        
        for(int i=1;i<nr-1;i++){
            v[i+1].push_back(1);
            
            for(int j=0;j<v[i].size()-1;j++){
                 v[i+1].push_back(v[i][j]+v[i][j+1]);    
            }
         v[i+1].push_back(1);
        }
        
        return v;
    }
};