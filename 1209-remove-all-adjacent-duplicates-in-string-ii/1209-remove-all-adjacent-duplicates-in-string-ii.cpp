class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>v;
        int n=s.length();
        
        v.push_back(make_pair(s[0],1));
        for(int i=1;i<n;i++){
            
            if(v.size()){
                
              auto ele=v.back();
            
             if(ele.first==s[i]){ 
                 v.pop_back();
                 ele.second++; 
                 if(ele.second%k != 0){
                     v.push_back(ele);
                 }
             }else{
                 v.push_back(make_pair(s[i],1));
             }
                
           }else{
                v.push_back(make_pair(s[i],1));
            }
        }
        
        string ans="";
        int nn=v.size();
        for(int i=0;i<nn;i++){
            int cnt=v[i].second;
            while(cnt--) ans+=v[i].first;
        }
        return ans;
    }
};