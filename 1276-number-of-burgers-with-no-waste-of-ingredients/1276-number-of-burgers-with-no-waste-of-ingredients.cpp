class Solution {
public:
    vector<int> numOfBurgers(int ts, int cs) {
          if(ts&1) return {};
        
          int lb=(ts/4)+((ts%4)?1:0);
          int ub=(ts/2);
        
          if(cs<lb or cs>ub) return {};
          
          int fm=(ts/4); 
        
          int ftke=0;
        
          while(ftke <= fm)
          {
              int bachelo=(ts - (ftke*4));
              int takenbytwo=(bachelo/2);
              
              if((ftke+takenbytwo) == cs){
                  return {ftke,takenbytwo};
              }
              
              ftke++; 
          }
          
         return {};
          
    }
};