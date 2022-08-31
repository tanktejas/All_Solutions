bool cmp(string s1,string s2){
  return s1.length() > s2.length();
}

class Solution {
public:
    
    string solve(string s)
    { 
        if(s=="") return "";
        
        int curr=0;
        string cc="";
        int n=s.length();
         
        vector<string>v;
        int start=0;
        int j=0; 
        
        for(start=j;start<n;j++) 
        {   
            if(s[j]=='1') curr++;
            else curr--; 
            
            if(curr==0){   
                v.push_back("1"+solve(s.substr(start+1,j-start-1))+"0");
                start=j+1;  
            }   
        } 
        
        sort(v.begin(),v.end(),greater<string>());
        
        string str="";  
        for(int i=0;i<v.size();i++)
        {      
            str+=v[i];
        }     
        
        return str;
        
    }
    
    string makeLargestSpecial(string s) {
        
       return solve(s);
        
    }
};