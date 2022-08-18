class Solution {
public:
    int countLatticePoints(vector<vector<int>>& c) {
        
        int cnt=0;
        int n=c.size();
        
        for(int i=0;i<=200;i++)
        {
            for(int j=0;j<=200;j++)
            {
                bool is=0;
            
                for(int k=0;k<n;k++)
                {
                    int fb=abs(i-c[k][0]);
                    int sb=abs(j-c[k][1]);
                
                    
                    fb*=fb;
                    sb*=sb;
                    
                    int rad=c[k][2];
                    
                    rad*=rad;
                    
                    if((fb +  sb) <= rad){
                        is=1;
                    }
                    
                }
                
                if(is){
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};