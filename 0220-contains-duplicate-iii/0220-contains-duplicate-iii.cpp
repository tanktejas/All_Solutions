class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int id, int vd) {
        int n=nums.size();
        
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(nums[i],i));
        }
        
        sort(v.begin(),v.end());
        
        int i=0,j=1;
        
        set<int>s;
        s.insert(v[0].second);
         
        while(j<n)
        {
            int curridx=v[j].second;
            int currval=v[j].first;
            
            while((currval - v[i].first) > vd)
            {  
                 s.erase(v[i].second);
                 i++;
            }
             
             
            if(!s.empty()){
            
            auto kk=s.lower_bound(curridx);
            
            int idx=(*kk);
             
           
            if(!s.empty() and kk!=s.end() and abs(curridx - idx) <= id ) { 
                return 1;
            }
            
            if(kk!=s.begin() and !s.empty())
            {
                kk--;  
                idx=(*kk);
                
                if(abs(curridx - idx) <= id){   
                    return 1;
                }  
            }
            
            }
            
            s.insert(curridx);
            
            j++;
        }
        
        return 0;
    }
};