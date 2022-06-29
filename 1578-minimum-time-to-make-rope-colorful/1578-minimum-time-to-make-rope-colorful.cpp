class Solution {
public:
    int minCost(string co, vector<int>& nt) {
         int cs=0,cm=0;
         int ans=0;
         int manyele=0;
        int n=nt.size();
         for(int i=0;i<n;)
         {
             char ch=co[i];
             manyele=0;
             cm=0;
             cs=0;
             while(i<n and co[i]==ch)
             {
                 cs+=nt[i];
                 cm=max(cm,nt[i]);
                 manyele++;
                 i++;
             }
             
             if(manyele > 1){
                 ans+=(cs-cm);
             }
             
         }        
        return ans;
    }
};