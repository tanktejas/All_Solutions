class TopVotedCandidate {
public:
    vector<int>winner,tt;
    
    
    TopVotedCandidate(vector<int>& p, vector<int>& t) {
        int n=p.size();
        vector<pair<int,int>>pp;
        tt=t;
        sort(tt.begin(),tt.end()); 
        
        for(int i=0;i<n;i++) pp.push_back(make_pair(t[i],p[i]));
        
        sort(pp.begin(),pp.end());   
        
        unordered_map<int,int>curr;
        int maxi=0,cw=0;
        
        for(int i=0;i<n;i++)
        {
            curr[p[i]]++;
            if(curr[p[i]]>=maxi)
            {
                maxi=curr[p[i]];
                cw=p[i];
            }  
            winner.push_back(cw);
        }
        
    }
    
    int q(int t) {
       
        auto ele=lower_bound(tt.begin(),tt.end(),t);
        int idx=(ele - tt.begin());
         
        if(idx==tt.size() or (tt[idx]!=t)){
            idx--; 
        }
        
        return winner[idx];
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */