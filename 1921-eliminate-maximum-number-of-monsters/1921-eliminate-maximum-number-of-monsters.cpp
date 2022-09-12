class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double>t;
        
        for(int i=0;i<n;i++)
        {
            double s=speed[i];
            double d=dist[i];
            
            double time=d/s;
            
            t.push_back(time);
        }
        
        sort(t.begin(),t.end());
        int ans=0;
        if(n==1) return 1;
        double ee=0;
        
        for(int i=0;i<n;i++)
        {  
            if(ee>=t[i]){
                return ans;
            }
            ans++;
            ee+=1; 
        }
        
        return ans;
    }
};