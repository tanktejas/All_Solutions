class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>fofn;
        map<int,int>ninf;
        int ans=1;
        
        for(int i=0;i<n;i++)
        {
            
            if(fofn.count(nums[i]))
            { 
                ninf[fofn[nums[i]]]--;
                
                
                if(ninf[fofn[nums[i]]]==0)
                { 
                    ninf.erase(fofn[nums[i]]); 
                }
            }  
            
            fofn[nums[i]]++;
            
            ninf[fofn[nums[i]]]++;
             
            
            if(ninf.size()==1)
            {
                for(auto ele : ninf)
                {
                    if(ele.second == 1 or ele.first == 1)
                    {
                        ans=max(ans,(i+1));
                    }
                }
                
            }else if(ninf.size()==2)
            {   
                vector<pair<int,int>>cur;
                 
                
                for(auto ele : ninf)
                {
                    cur.push_back({ele.first,ele.second});
                }   
                
                
                sort(cur.begin(),cur.end());
                 
                // if(i==1) 
                //     cout<<cur[0].first<<' '<<cur[0].second<<endl;
                
                if((cur[0].first == 1 and cur[0].second == 1) or ((cur[1].first - cur[0].first)==1 and cur[1].second==1))
                {   
                    ans=max(ans,(i+1));
                } 
                
            }
        }
         
        
        return ans;
        
    }
};