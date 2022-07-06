class Solution {
public:
    
       vector<string>ans; 
    
    bool addanstell(string s1,string s2,string tar){
        int i=s1.length()-1,j=s2.length()-1,carry=0;
        string ans="";
        while(i>=0 and j>=0){
            int tot=(s1[i]-'0')+(s2[j]-'0')+carry;
            carry=tot/10;
            ans+=(to_string(tot%10));
            i--;
            j--;
        }
        
        while(i>=0){
            int tot=((s1[i]-'0')+carry);
            ans+=to_string(tot%10);
            carry=tot/10;
            i--;
        }
        
         while(j>=0){
            int tot=((s2[j]-'0')+carry);
            ans+=to_string(tot%10);
            carry=tot/10;
            j--;
        }
        
        if(carry>0) ans+=to_string(carry);
        
        reverse(ans.begin(),ans.end());
        
        return ans==tar;
    }
    
      
     bool find(int idx,vector<string> &tmp,string str){
        if(tmp.size()>=3){ 
            int n=tmp.size()-1; 
            
            if(!addanstell(tmp[n-1],tmp[n-2],tmp[n])) return 0;
        } 
        
        if(idx==str.length()){
            if(tmp.size()>2){
              ans=tmp; 
              return 1;
           }
            return 0;  
        }
        
        if(str[idx]=='0'){
            tmp.push_back("0");
            if(find(idx+1,tmp,str)) return 1;
            tmp.pop_back();
            return 0;
        }
        
        for(int i=idx;i<str.length() ;i++){  
            
                   string chosen=str.substr(idx,(i-idx+1)); 
                   // long long rr=stoll(chosen);  
                   tmp.push_back(chosen);
                   if(find(i+1,tmp,str)){
                         return 1;
                   }  
                  tmp.pop_back();
            } 
        return 0;
    
    }
           
    bool isAdditiveNumber(string num) {
        vector<string>tmp;
        find(0,tmp,num);
        return ans.size();
    }
};