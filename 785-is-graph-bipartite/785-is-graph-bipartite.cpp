class Solution {
public:
    bool find(vector<vector<int>>& g,vector<int> &color,int n,int start,int currcolo){
         if(color[start]!=2 and color[start]!=currcolo){
             return false;
         }
         if(color[start]!=2){
             return 1;
         }  
         color[start]=currcolo;
        
         for(auto ele:g[start]){
             if(!find(g,color,n,ele,currcolo xor 1)){
                 return 0;
             }
         }
        
        return 1;
    }
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        
        vector<int>c(n,2);
        for(int i=0;i<n;i++){
          if(c[i]==2){
             if(!find(g,c,n,i,0)) return 0;
          }
        }
        return 1;
    }
};