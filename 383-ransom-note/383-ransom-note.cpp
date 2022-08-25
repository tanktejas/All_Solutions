class Solution {
public:
    bool canConstruct(string r, string ma) {
          vector<int>v(32,0);
        
         for(int i=0;i<ma.size();i++)
         {
             v[ma[i]-'a']++;
         }
        
         for(int i=0;i<r.size();i++)
         {
             v[r[i]-'a']--;
         }
        
         for(int i=0;i<32;i++)
         {
             if(v[i]<0) return 0;
         }
         
         return 1;
        
    }
};