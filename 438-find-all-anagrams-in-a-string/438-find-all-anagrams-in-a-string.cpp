class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        
        unordered_map<char,int>rn,fi;
        for(int i=0;i<p.length();i++)
        {
           fi[p[i]]++; 
        }
        
        int noofdi=0;
        int m=p.length();
        int i=0,j=0;
        int n=s.length();
        while(j<n)
        {
             if((j-i)<m){
                 if(rn[s[j]] < fi[s[j]]) noofdi++;
                 rn[s[j]]++;
                 j++; 
             }else{
                 if(noofdi == m) ans.push_back(i);
                 
                 if(rn[s[i]] <= fi[s[i]]) noofdi--; 
                 rn[s[i]]--; 
                 i++;
                  
                 if(rn[s[j]] < fi[s[j]]) noofdi++;  
                 rn[s[j]]++;
                 j++;
             }  
            cout<<i<<' '<<j<<" "<<noofdi<<endl;
        }
        
        if(noofdi == m) ans.push_back(i);
        
        return ans;
    }
};