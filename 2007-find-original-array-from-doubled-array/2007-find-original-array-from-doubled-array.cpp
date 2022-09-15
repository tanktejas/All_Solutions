class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        int n=ch.size();
        
        vector<int>v;
        
        if(n&1) return v;
        
        sort(ch.begin(),ch.end());
        
        map<int,int>m;
        
        for(int i=0;i<n;i++){
            m[ch[i]]++;
        }
        bool bo=1;
        
        
        for(int i=0;i<n;i++){
            if(m[ch[i]]){ 
                
                if(m[ch[i]*2]) m[ch[i]*2]--;
                else bo=0;
                
                v.push_back(ch[i]);
                 m[ch[i]]--;
            }
            
        }
        
        if(bo)
           return v;
        else 
           return {};
    } 
};