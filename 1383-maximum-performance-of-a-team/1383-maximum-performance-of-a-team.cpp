#define ll unsigned long long

class Solution {
public:
    int mod=1e9 + 7;  
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        
        vector<pair<int,int>>v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i].first=ef[i];
            v[i].second=sp[i];
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        priority_queue<ll,vector<ll>,greater<ll>>q;
        ll sum=0;
        ll maxi=0;
        
        for(int i=0;i<n;i++)
        {
             q.push(v[i].second);
             sum=(sum + v[i].second);
            
             if(q.size()>k)
             {
                 sum-=q.top();
                 q.pop();
             }
               
            ll rr=(sum*v[i].first);
             
            if(rr > maxi)
            {
               maxi=rr; 
            }
        }
        
        return maxi%mod;
    }
};