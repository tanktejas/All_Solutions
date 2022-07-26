class Solution {
public:
    string minWindow(string s, string t) {
        int start=0;
        int len=0;
        int sn=s.length();
        int tn=t.length();
        int ans=INT_MAX;
        
         unordered_map<char,int>ft;
         unordered_map<char,int>rt;
        
        for(int i=0;i<tn;i++){
           if(ft[t[i]]==0){
               ft[t[i]]=1; 
           }else{
               ft[t[i]]++; 
           }  
        } 
        
        int cov=0;
        int i=0,j=0;
        
        while(j<sn)
        {  
            if(cov==tn)
            {  
                if((j-i)<ans){
                    ans=(j-i); 
                    start=i;
                }
            }
            
            if(cov!=tn)
            {   
                if(ft[s[j]])
                  rt[s[j]]++;  
                if(ft[s[j]]!=0 and rt[s[j]]<=ft[s[j]]) cov++;  
                j++;  
            }else{  
               if(ft[s[i]]){ 
                if(rt[s[i]] <= ft[s[i]])
                  cov--;   
                rt[s[i]]--;  
                i++;  
               }
               else
               { 
                   i++;
               } 
            }  
        }
         
        while(i<sn){
            
           if(cov==tn)
            {  
                if((j-i)<ans){ 
                    ans=(j-i);
                    start=i;
                }
            }
             
             if(ft[s[i]]){  
                if(rt[s[i]] <= ft[s[i]])
                  cov--;  
                 
                rt[s[i]]--;   
                i++;  
               }  
               else
               { 
                   i++;
               } 
        }
        
        if(ans==INT_MAX) return "";
        else return s.substr(start,ans);
        
    }
};