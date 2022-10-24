class Solution {
public:
    
    
    int stoneGameVI(vector<int>& av, vector<int>& bv) {
        
        int n=av.size();
        
        vector<vector<int>>v;
        
        for(int i=0;i<n;i++)
        { 
            v.push_back({bv[i]+av[i],i});
        }
        
        sort(v.begin(),v.end(),greater<vector<int>>());
        
        int asc=0,bsc=0;
         
        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                asc+=av[v[i][1]];
            }else{
                bsc+=bv[v[i][1]];
            }
        }    
        
        return asc > bsc ? 1 : ((asc == bsc) ? 0 : -1);
    }
};