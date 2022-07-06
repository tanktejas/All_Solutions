class Solution {
public:
    vector<int>ans; 
      
    bool find(int idx,vector<int> &tmp,string str){
        if(tmp.size()>=3){ 
            int n=tmp.size()-1; 
            long long pp= tmp[n-1];
            long long p2= tmp[n-2];
            long long oo=(long long)(pp+p2);
            if(tmp[n]!=oo) return 0;
        } 
        
        if(idx==str.length()){
            if(tmp.size()>2){
              ans=tmp; 
              return 1;
           }
            return 0;  
        }
        
        if(str[idx]=='0'){
            tmp.push_back(0);
            if(find(idx+1,tmp,str)) return 1;
            tmp.pop_back();
            return 0;
        }
        
        for(int i=idx;(i-idx+1)<=10 and i<str.length() ;i++){  
            
                   string chosen=str.substr(idx,(i-idx+1)); 
                   long long rr=stoll(chosen);  
                   tmp.push_back(rr);
                   if(find(i+1,tmp,str)){
                         return 1;
                   }  
                  tmp.pop_back();
            }
        return 0;
    
    }
          
    vector<int> splitIntoFibonacci(string num) {
         vector<int>tmp;
         find(0,tmp,num);
         return ans;
    }
};