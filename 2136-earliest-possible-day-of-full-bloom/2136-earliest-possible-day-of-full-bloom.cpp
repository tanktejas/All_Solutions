class Solution {
public:
    int earliestFullBloom(vector<int>&pt, vector<int>& gt) {
         
        
        vector<pair<int,int>>v;
        int n=gt.size();
        
        for(int i=0;i<n;i++)
        {
            v.push_back({gt[i],pt[i]});
        }
        
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b)
             {
                 return a.first > b.first;
             });
        
        int maxi=0;
        
        int pela=0;
        
        for(int i=0;i<n;i++)
        { 
            maxi=max(maxi,pela+v[i].first+v[i].second);
            pela+=(v[i].second);
        }
         
        return maxi;
    }
};