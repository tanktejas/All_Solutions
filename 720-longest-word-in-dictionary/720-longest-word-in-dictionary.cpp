class Solution {
public:
    
    vector<vector<string>>v;
    string ans;
    
    void find(int idx,string prev)
    {
        if(prev.length() > ans.length())
        {
            ans=prev;
        }else if(prev.length() == ans.length())
        {
            if(prev < ans) ans=prev; 
        }
        
        if(idx>30){
            return ;
        }
         
        int len=v[idx].size();
        
        for(int i=0;i<len;i++)
        { 
            string curr=v[idx][i];  
            if((prev+curr[idx-1])==curr){  
                find(idx+1,curr);
            }
            
        }
        
    }
    
    string longestWord(vector<string>& wo) {
        int n=wo.size();
        v.resize(31);
        ans="";
        
        for(int i=0;i<n;i++)
        {
            v[wo[i].size()].push_back(wo[i]);
        }
        
        find(1,"");
        
        return ans;
    }
};