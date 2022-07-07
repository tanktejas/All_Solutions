class Solution {
public:
    bool checkInclusion(string s1, string s2) { 
        
        int n=s1.length(),m=s2.length();
        
        if(m<n) return 0;
        
        vector<vector<int>>v(m,vector<int>(26,0));
        vector<int>freq(26,0);
        
        for(int i=0;i<n;i++) freq[s1[i]-'a']++;
        
        int i=0,j=0;
        
        for(j=0;j<n;j++){
            if(j==0){
                v[j][s2[j]-'a']++;
            }else{
                for(int k=0;k<26;k++){
                   v[j][k]+=v[j-1][k];
                } 
                v[j][s2[j]-'a']+=1;
            }
        }
         
        
        bool is=1;
        for(int p=0;p<26;p++){
            if(freq[p]!=v[j-1][p]) is=0;
        }
        
       
        if(is) return 1;
        
        while(j<m){
            
             for(int h=0;h<26;h++){
                 v[j][h]=v[j-1][h];
             } 
             v[j][s2[j]-'a']++;
             
              bool is=1;
             for(int h=0;h<26;h++){
                   if((v[j][h]-v[i][h])!=freq[h]) is=0;
             }
            
             if(is) return 1;
            
             i++;
             j++;    
        }
        
        return 0;
    }
};