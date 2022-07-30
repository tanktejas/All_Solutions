class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<int>v(27,0);
        int n=w2.size();
        int m=w1.size();
        
        for(int i=0;i<n;i++)
        {
            string ss=w2[i];
            sort(ss.begin(),ss.end());
            
            int j=0;
            while(j<ss.length())
            {
                char ch=ss[j];
                int cnt=0;
                
                while(j<ss.length() and ch==ss[j])
                {
                    j++;
                    cnt++;
                }
                v[ch-'a']=max(v[ch-'a'],cnt);
            }
             
        }
         
        vector<string>ans;
        vector<int>curr(27);
        
        for(int i=0;i<m;i++)
        {
            string dd=w1[i];
            bool bo=1; 
            
            curr.clear();
            curr.resize(27,0);
            
            for(int k=0;k<dd.length();k++)
            {
                curr[dd[k]-'a']++;    
            }
            
            for(int j=0;j<27;j++)
            {
                if(v[j] > curr[j])
                { 
                    bo=0;
                }
            } 
        
            if(bo) ans.push_back(w1[i]);            
        }
        
        return ans;
    }
};