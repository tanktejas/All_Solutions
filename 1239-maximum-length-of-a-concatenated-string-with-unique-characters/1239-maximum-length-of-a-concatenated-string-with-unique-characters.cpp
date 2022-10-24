class Solution {
public:
    
    unordered_map<int,int>mp;
    
    int find(vector<string> &arr,int idx,int n)
    {
        if(idx==n) return 0;
        
        string c=arr[idx];
        
        bool canpick=1;
        
        int kk=c.length();
        
        for(int j=0;j<kk;j++)
        {
            mp[c[j]-'a']++;
            if(mp[c[j]-'a'] >= 2)
            {
                canpick=0;
            }
        }
        
        int pick=0,notpick=0;
        
        if(canpick)
        {
            pick=find(arr,idx+1,n);       
        }
        
        for(int j=0;j<kk;j++)
        {
            mp[c[j]-'a']--;
        }
        
        if(canpick)
        {
            pick+=kk;
        }
        
        notpick=find(arr,idx+1,n);
        
        return max(pick,notpick);
    }
    
    int maxLength(vector<string>& arr) {
    
        int n=arr.size();
        
        return find(arr,0,n);
        
    }
};