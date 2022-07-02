class Solution {
public:
    int mod=1000000007;
    
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        int width=0;
        for(int i=0;i<vc.size();i++){
            if(i==0) width=vc[i];
            else width=max(width,vc[i]-vc[i-1]);
        }
        width=max(width,w - vc[vc.size()-1]);
        
       int height=0;
        for(int i=0;i<hc.size();i++){
            if(i==0) height=hc[i];
            else height=max(height,hc[i]-hc[i-1]);
        }
        height=max(height,h - hc[hc.size()-1]);
        
        long long ans=height%mod;
        ans=(ans*width)%mod;
        return ans;
    } 
};