class Solution {
public:
    unordered_map<string,int>m;
    
    bool find(string s1,string s2){
        int n=s1.length();
        
        int cando=0;
        
        if(s1==s2) return 1;
        
        if(n==1) return 0;
        
        if(m.find(s1+" "+s2)!=m.end()) return m[s1+" "+s2];
        
         
        for(int i=0;i<n-1;i++){   
           if(find(s1.substr(0,i+1),s2.substr(0,i+1))==1 and find(s1.substr(i+1),s2.substr(i+1))){
               cando=1;
           }    
            if(cando) return 1;
            
           if(find(s1.substr(0,i+1),s2.substr(n-(i+1)))==1 and find(s1.substr(i+1),s2.substr(0,n-(i+1)))){
               cando=1;
           }   
            if(cando) return 1;
        }
        
        m[s1+" "+s2]=cando;
        
        return m[s1+" "+s2];
        
    }
    
    bool isScramble(string s1, string s2) {
        return find(s1,s2);
    }
};