class Solution {
public:
    bool canReach(string s, int mj, int mxj) {
       
      int n=s.length();
      vector<int>vis(n,0);
        
      queue<int>q;
      q.push(0);
      vis[0]=1;
      
      int fr=0;
    
      while(!q.empty()){
          int ele=q.front();
          q.pop(); 
          
          if(ele==n-1) return 1;
          
          for(int i=max(fr,(ele+mj));i<=min(n-1,(ele+mxj));i++){
              if(!vis[i] and s[i]=='0'){ 
                  vis[i]=1;
                  q.push(i);
              }
          }
          
          fr=ele+mxj;
          
      }
        
    return 0;
    }
};