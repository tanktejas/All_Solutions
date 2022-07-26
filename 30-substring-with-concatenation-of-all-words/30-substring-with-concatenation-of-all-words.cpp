class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        unordered_map<string,int>m;
        int n=words.size();
        int one=words[0].length();
        int len=s.length();

        for(int i=0;i<n;i++) m[words[i]]++;
        
        cout<<(len-(one*n));
        
        for(int i=0;i<=(len-(one*n));i++)
        {
             unordered_map<string,int>mp=m;
             bool is=1;
             int levai=0;
             for(int j=i;j<(i + (n*one));j+=one)
             {
                 
                 string curr=s.substr(j,(one));
                 if(mp[curr]==0){
                     is=0;  
                     break;
                 }else{
                     
                     mp[curr]--;
                     if(mp[curr]==0) levai++;
                     
                 }
                 
             } 
            
            if(is) ans.push_back(i);
            
        }
        
        return ans;
    }
};