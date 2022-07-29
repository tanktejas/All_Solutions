class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        int n=words.size();  
    
        int pn=pattern.length();
            
           
        vector<int>har;
                                     
        for(int i=0;i<n;i++)
        {
            string curr=words[i];
            
            if(curr.size()==pattern.size())
            {
               har.clear();
                
             
              int pi=0,ci=0;
              bool bo=1;
              
              map<char,char>mapped;
              map<char,char>currmaped;
                
              while(pi<pn and ci<pn)
              {
                  char oo=pattern[pi],pp=curr[ci];
                  while(pi<pn and pattern[pi]==oo) pi++;
                  while(ci<pn  and curr[ci]==pp) ci++;
                  
                  if((mapped.find(oo)!=mapped.end() and mapped[oo]!=pp) or (currmaped.find(pp)!=currmaped.end() and currmaped[pp]!=oo)){
                      bo=0;
                  } 
                  
                  mapped[oo]=pp;
                  currmaped[pp]=oo;
                  
                  if(pi!=ci) bo=0;
              }
                
                if(bo) ans.push_back(words[i]);
                
            }
            
                
        }
        
        return ans;
    }
};