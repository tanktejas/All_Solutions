class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& po) {
        sort(po.begin(),po.end());
        int n=po.size();
        int f=po[0][0],s=po[0][1];
        
        int ar=0;
        
        for(int i=1;i<n;i++)
        { 
            if(po[i][0] <= s){  
                f=po[i][0];
                s=min(s,po[i][1]);
            }else{
                ar++;
                f=po[i][0];
                s=po[i][1];
            }
        }  
        
        return ar+1;
        
    }
};