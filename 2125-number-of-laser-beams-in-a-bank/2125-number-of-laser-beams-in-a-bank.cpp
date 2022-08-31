class Solution {
public:
    int numberOfBeams(vector<string>& ba) {
        
        int cnt=0;
        int n=ba.size();
        int m=ba[0].size();
        int prev=0;
        
        for(int i=0;i<n;i++)
        {
            int curr=0;
            for(int j=0;j<m;j++)
            {
               if(ba[i][j]=='1'){
                   curr++;
               }
            }
            
            if(curr){
                cnt+=(curr*prev);
                prev=curr;
            }
        }
        
        return cnt;
        
    }
};